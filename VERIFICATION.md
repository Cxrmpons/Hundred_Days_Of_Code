# Verification report

Days 1–82 were checked on 3 November 2026 using GCC 16.1.0 (MSYS2 UCRT64). All 132 programs compiled without warnings. 234 of 245 published cases matched and all 130 additional checks passed.

| Check | Result |
| --- | ---: |
| Day folders | 82 |
| Numbered question statements and C files | 132 |
| Warning-free builds | 132/132 |
| Matching published cases | 234/245 |
| Passing additional cases | 130/130 |
| Questions matching every published case | 122/132 |

## Method

The extracted question bank matches Git blob `ce9a9ac9b557f114a6c3285ca2439ce2e5fd54fc`. Question order follows the published renderer. The repository retains every sample input and expected output in the test fixtures, along with the available sample explanations. [Question bank snapshot](https://github.com/maitysoumik/basic-coding-with-c/blob/d9ae46c9e8a9c8d97b5ab3f3848daefdd1611307/questions2.json) · [Test fixtures](tests/cases.json)

The runner compiles each file with `gcc -std=c11 -Wall -Wextra -pedantic -Werror` and links with `-lm`. It launches each case in a new temporary directory, checks the exit status, and compares text after normalizing CRLF and allowing one terminal newline. Leading spaces, blank lines within patterns, and trailing spaces are significant. A timeout or missing output file fails the case.

For Q122–129, the published input describes files or filesystem state. The fixtures create those files and provide the filename or text that a user would enter. Q127 compares the contents of output.txt. Q121, Q124, Q125, and Q130 also check written files. Q131's “No input” means an empty input stream.

## Published sample discrepancies

Each case below remains a failed comparison. Escaped newlines and spaces inside the quoted strings show the exact line structure.

### Q4, sample 1

With radius 7, 2πr rounds to 43.98. The published area also uses π to higher precision than 3.14. [Q4](Day2/Question_4.c)

```text
Expected  "Area=153.94, Circumference=43.96"
Observed  "Area=153.94, Circumference=43.98"
```

### Q9, sample 2

Annual compounding gives 5000 × (1.07³ − 1) = 1125.215, which rounds to 1125.22. [Q9](Day5/Question_9.c)

```text
Expected  "Simple Interest=1050, Compound Interest=1125.76"
Observed  "Simple Interest=1050, Compound Interest=1125.22"
```

### Q44, sample 1

The first three terms total 1 + 3/4 + 5/6 = 2.58333…, which rounds to 2.6. [Q44](Day22/Question_44.c)

```text
Expected  "Approximate sum: 3.3"
Observed  "Approximate sum: 2.6"
```

### Q45, sample 1

Summing the listed fractions gives 1.783549… after three terms and 2.843198… after five. [Q45](Day23/Question_45.c)

```text
Expected  "Approximate sum: 1.56"
Observed  "Approximate sum: 1.78"
```

### Q45, sample 2

Summing the listed fractions gives 1.783549… after three terms and 2.843198… after five. [Q45](Day23/Question_45.c)

```text
Expected  "Approximate sum: 2.22"
Observed  "Approximate sum: 2.84"
```

### Q50, sample 2

The second case has the same empty input as the first, but supplies an indentation note as its output. The first case and the independent pattern comparison pass. [Q50](Day25/Question_50.c)

```text
Expected  "Note: Spaces indicate indentation."
Observed  "*****\n ****\n  ***\n   **\n    *"
```

### Q52, sample 1

The published output describes the diagram in prose. An independent comparison checks the groups of 1, 3, 5, 3, and 1 stars on separate lines, including the blank separators. [Q52](Day26/Question_52.c)

```text
Expected  "Pattern with stars spaced irregularly as shown."
Observed  "\n*\n\n*\n*\n*\n\n*\n*\n*\n*\n*\n\n*\n*\n*\n\n*"
```

### Q54, sample 1

The published output describes the diagram in prose. The separate diagram test checks all seven rows and their indentation. [Q54](Day27/Question_54.c)

```text
Expected  "Pattern with layers of stars as shown."
Observed  "   *\n  ***\n *****\n*******\n *****\n  ***\n   *"
```

### Q120, sample 1

The examples capitalize each word. The first expected output drops the final period, while the other two retain it. This solution capitalizes word initials and preserves punctuation. [Q120](Day70/Question_120.c)

```text
Expected  "I Am Trying To Build Logic"
Observed  "I Am Trying To Build Logic."
```

### Q123, sample 1

The two-line fixture contains 33 characters including the newline and six whitespace-delimited words. The second line has four words. The file has no trailing newline. [Q123](Day73/Question_123.c)

```text
Expected  "Characters: 31\nWords: 5\nLines: 2"
Observed  "Characters: 33\nWords: 6\nLines: 2"
```

### Q126, sample 1

The sample uses a placeholder for the contents of a file whose text is unspecified. The fixture supplies one line. The separate content check confirms the program prints it. [Q126](Day76/Question_126.c)

```text
Expected  "File opened successfully.\n(Displays file content)"
Observed  "File opened successfully.\nExample file content."
```

## Commit checkpoints

Each checkpoint followed compilation and execution of the corresponding daily cases. The totals above come from the subsequent full run of the final sources.

| Through day | Programs | Day commit |
| ---: | ---: | --- |
| 10 | 20 | [d66d854](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/d66d8542a0741f3acb3f5af016eeab457b4466a0) |
| 20 | 40 | [224e319](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/224e3196cbd4e33b0f540ea59d57eadf6eacf837) |
| 30 | 60 | [707318c](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/707318cb0a67522f8ce65485fab3227f2e9e0f6f) |
| 40 | 80 | [09f96eb](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/09f96ebf204f762035e2fae887010010359a15a7) |
| 50 | 100 | [c33995d](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/c33995df8ba42aca296c268af4791a6f3e3d1663) |
| 60 | 110 | [78c2293](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/78c2293548cf010a4f6fdf7b101ada6d04514266) |
| 70 | 120 | [06b3beb](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/06b3beba83a1e72127e84f3f37ff6a8ea17f0d09) |
| 80 | 130 | [bb73ef9](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/bb73ef916b13a62caacada22efb7af6e5386c77b) |
| 82 | 132 | [044dab8](https://github.com/Cxrmpons/Hundred_Days_Of_Code/commit/044dab818ee5f92854d8af29ad21360d43a7a4cb) |
