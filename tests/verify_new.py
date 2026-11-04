"""Build and test the C11 solutions added after Day 82 (Python 3.9+)."""

import argparse
import json
import os
from pathlib import Path
import subprocess
import tempfile


def run_cases(question, executable):
    day = question["day"]
    result = dict(day=day, compiled=True, samplesPassed=0, samplesFailed=0,
                  samplesDescriptive=0, edgesPassed=0, edgesFailed=0)
    for case in question["cases"]:
        stdin = case.get("stdin", case["input"])
        if stdin and not stdin.endswith("\n"):
            stdin += "\n"
        process = subprocess.run([str(executable)], input=stdin.encode(),
                                 capture_output=True, timeout=5, cwd=executable.parent)
        output = process.stdout.decode().replace("\r\n", "\n").removesuffix("\n")
        if case["kind"] == "descriptive":
            # The published text supplies neither five records nor a literal table.
            result["samplesDescriptive"] += 1
            print(f"Day {day} descriptive sample attempted: exit {process.returncode}, "
                  f"stdout {output!r}. The five-record fixture is checked separately.")
            continue
        passed = output == case["output"] and process.returncode == case.get("exit", 0)
        group = "samples" if case["kind"] == "sample" else "edges"
        result[group + ("Passed" if passed else "Failed")] += 1
        if not passed:
            print(f"Day {day}, {case['name']}: expected {case['output']!r} "
                  f"(exit {case.get('exit', 0)}), got {output!r} (exit {process.returncode})")
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--day", type=int, help="Run a single day in the fixture.")
    parser.add_argument("--json", type=Path, help="Write daily counts as JSON.")
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    suite = json.loads((root / "tests/days83-96.json").read_text(encoding="utf-8"))
    selected = [q for q in suite if args.day is None or q["day"] == args.day]
    if not selected:
        parser.error("No fixtures for the selected day.")

    results = []
    with tempfile.TemporaryDirectory() as temp:
        exe = Path(temp) / ("question.exe" if os.name == "nt" else "question")
        for question in selected:
            day, number = question["day"], question["number"]
            source = root / f"Day{day:02}/Question_{number}.c"
            subprocess.run(["gcc", "-std=c11", "-Wall", "-Wextra", "-pedantic",
                            "-Werror", str(source), "-o", str(exe)], check=True)
            results.append(run_cases(question, exe))
    if args.json:
        args.json.write_text(json.dumps(results, indent=2) + "\n", encoding="utf-8")
    print(f"{len(results)} compiled without warnings.")
    for group in ("samples", "edges"):
        passed = sum(row[group + "Passed"] for row in results)
        failed = sum(row[group + "Failed"] for row in results)
        print(f"{group}: {passed} passed, {failed} failed")
    return int(any(row["samplesFailed"] or row["edgesFailed"] for row in results))


if __name__ == "__main__":
    raise SystemExit(main())
