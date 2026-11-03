"""Compile the selected C11 solutions and compare their outputs with the saved cases."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def compare(executable, case, directory):
    for name, content in case.get("files", {}).items():
        (directory / name).write_bytes(content.encode("utf-8"))
    stdin = case.get("stdin", case["input"])
    if stdin and not stdin.endswith("\n"):
        stdin += "\n"
    run = subprocess.run(
        [str(executable)], input=stdin.encode("utf-8"), cwd=directory,
        capture_output=True, timeout=8,
    )
    actual = run.stdout.decode("utf-8").replace("\r\n", "\n")
    if "observe" in case:
        path = directory / case["observe"]
        actual = path.read_text(encoding="utf-8") if path.is_file() else "<file missing>"
    expected = case.get("expected_content", case["output"])
    passed = actual.removesuffix("\n") == expected.removesuffix("\n")
    passed &= run.returncode == case.get("exit", 0)
    for name, expected_file in case.get("after", {}).items():
        path = directory / name
        passed &= path.is_file() and path.read_text(encoding="utf-8") == expected_file
    return {"passed": passed, "actual": actual.removesuffix("\n"), "exit": run.returncode}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--day", type=int, choices=range(1, 83), metavar="1-82")
    parser.add_argument("--json", type=Path, help="Write detailed results to this path.")
    args = parser.parse_args()
    suite = json.loads((ROOT / "tests/cases.json").read_text(encoding="utf-8"))
    results = {}
    failures = {"sample": 0, "edge": 0}
    counts = {"sample": 0, "edge": 0}
    build_failures = 0
    with tempfile.TemporaryDirectory() as temp:
        build = Path(temp)
        exe = build / ("question.exe" if os.name == "nt" else "question")
        for question in suite:
            if args.day and args.day != question["day"]:
                continue
            number = question["id"]
            source = ROOT / f"Day{question['day']}/Question_{number}.c"
            compiler = subprocess.run(
                ["gcc", "-std=c11", "-Wall", "-Wextra", "-pedantic", "-Werror",
                 str(source), "-o", str(exe), "-lm"], capture_output=True,
            )
            if compiler.returncode:
                build_failures += 1
                print(f"Q{number} compilation failed\n{compiler.stderr.decode(errors='replace')}")
                results[str(number)] = {"compiled": False, "cases": []}
                continue
            cases = []
            for case in question["cases"]:
                kind = case["kind"]
                counts[kind] += 1
                with tempfile.TemporaryDirectory(dir=temp) as sandbox:
                    try:
                        result = compare(exe, case, Path(sandbox))
                    except (OSError, subprocess.TimeoutExpired, UnicodeError) as error:
                        result = {"passed": False, "error": str(error)}
                cases.append(dict(kind=kind, **result))
                if not result["passed"]:
                    failures[kind] += 1
                    print(f"Q{number} {kind} {case['number']} failed: {result!r}")
            results[str(number)] = {"compiled": True, "cases": cases}
    if args.json:
        args.json.write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding="utf-8")
    print(f"{len(results)-build_failures}/{len(results)} compiled")
    for kind in counts:
        print(f"{kind}: {counts[kind]-failures[kind]}/{counts[kind]} passed")
    return int(bool(build_failures or any(failures.values())))


if __name__ == "__main__":
    raise SystemExit(main())
