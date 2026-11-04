# 100 Days of Code in C

133 solutions for Days 1–83 of the UPES challenge. Days 1–50 have two questions per day. Days 51–83 have one. Each C11 program stands alone and opens with the original numbered statement. [Challenge website](https://maitysoumik.github.io/basic-coding-with-c/) · [Published question bank](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json)

This catch-up work was AI-assisted, including implementation and test preparation.

## Build and run

From the repository root, compile one source file at a time. Link the math library for programs that use it. For example, Q17 accepts the three coefficients of a quadratic equation.

```sh
gcc -std=c11 -Wall -Wextra -pedantic Day09/Question_17.c -o roots -lm
echo "1 -3 2" | ./roots
```

On Windows PowerShell, name the executable `roots.exe` and run `"1 -3 2" | ./roots.exe`. The example prints `Roots are real and different: 2, 1`.

For the file exercises, use a scratch working directory. Programs read and write the filenames described in their statements. Q123, Q125, Q126, and Q128 take a filename on a line. Q124 takes source and destination paths on separate lines. Q125 takes the appended text on the following line. Q121 and Q130 accept the published labeled inputs. Q130 also accepts a record count followed by single-word name, roll number, and marks for each student.

## Verification

All 1 new programs compiled without warnings with GCC 16.1.0. 1/1 published cases with concrete expected output matched. All 14 additional checks passed. [Verification report](VERIFICATION.md) · [New test cases](tests/days83-96.json)

With Python 3.9+ and GCC on the path, run the new checks from the repository root. Add `--day 83` to test just Day 83.

```sh
python tests/verify_new.py
```

The earlier verification run covered all 132 programs through Day 82. All compiled without warnings, 234 of 245 published cases matched and all 130 additional checks passed. The report documents the 11 discrepancies. [Historical test fixtures](https://github.com/Cxrmpons/Hundred_Days_Of_Code/blob/509d88231f038ca8cc10d6c0ef36863a2adad720/tests/cases.json) · [Historical test runner](https://github.com/Cxrmpons/Hundred_Days_Of_Code/blob/509d88231f038ca8cc10d6c0ef36863a2adad720/tests/verify.py)

## Historical Git simulation

The hackathon simulation assigns Day 1 to August 14, 2026 and Day 82 to November 3. Day 83 is dated November 4 in India Standard Time (UTC+05:30). Both the author and committer timestamps follow the simulation. The new programs were implemented and tested on November 23, 2026.

## Day-wise progress

The last column counts matching published samples. Each solution link opens the statement and the implementation.

| Day | Solutions | Published samples passed |
| ---: | --- | ---: |
| 1 | [Q1](Day01/Question_1.c) · [Q2](Day01/Question_2.c) | 4/4 |
| 2 | [Q3](Day02/Question_3.c) · [Q4](Day02/Question_4.c) | 3/4 |
| 3 | [Q5](Day03/Question_5.c) · [Q6](Day03/Question_6.c) | 4/4 |
| 4 | [Q7](Day04/Question_7.c) · [Q8](Day04/Question_8.c) | 4/4 |
| 5 | [Q9](Day05/Question_9.c) · [Q10](Day05/Question_10.c) | 3/4 |
| 6 | [Q11](Day06/Question_11.c) · [Q12](Day06/Question_12.c) | 5/5 |
| 7 | [Q13](Day07/Question_13.c) · [Q14](Day07/Question_14.c) | 5/5 |
| 8 | [Q15](Day08/Question_15.c) · [Q16](Day08/Question_16.c) | 6/6 |
| 9 | [Q17](Day09/Question_17.c) · [Q18](Day09/Question_18.c) | 7/7 |
| 10 | [Q19](Day10/Question_19.c) · [Q20](Day10/Question_20.c) | 5/5 |
| 11 | [Q21](Day11/Question_21.c) · [Q22](Day11/Question_22.c) | 5/5 |
| 12 | [Q23](Day12/Question_23.c) · [Q24](Day12/Question_24.c) | 7/7 |
| 13 | [Q25](Day13/Question_25.c) · [Q26](Day13/Question_26.c) | 5/5 |
| 14 | [Q27](Day14/Question_27.c) · [Q28](Day14/Question_28.c) | 4/4 |
| 15 | [Q29](Day15/Question_29.c) · [Q30](Day15/Question_30.c) | 4/4 |
| 16 | [Q31](Day16/Question_31.c) · [Q32](Day16/Question_32.c) | 4/4 |
| 17 | [Q33](Day17/Question_33.c) · [Q34](Day17/Question_34.c) | 4/4 |
| 18 | [Q35](Day18/Question_35.c) · [Q36](Day18/Question_36.c) | 4/4 |
| 19 | [Q37](Day19/Question_37.c) · [Q38](Day19/Question_38.c) | 4/4 |
| 20 | [Q39](Day20/Question_39.c) · [Q40](Day20/Question_40.c) | 4/4 |
| 21 | [Q41](Day21/Question_41.c) · [Q42](Day21/Question_42.c) | 4/4 |
| 22 | [Q43](Day22/Question_43.c) · [Q44](Day22/Question_44.c) | 3/4 |
| 23 | [Q45](Day23/Question_45.c) · [Q46](Day23/Question_46.c) | 1/3 |
| 24 | [Q47](Day24/Question_47.c) · [Q48](Day24/Question_48.c) | 2/2 |
| 25 | [Q49](Day25/Question_49.c) · [Q50](Day25/Question_50.c) | 2/3 |
| 26 | [Q51](Day26/Question_51.c) · [Q52](Day26/Question_52.c) | 1/2 |
| 27 | [Q53](Day27/Question_53.c) · [Q54](Day27/Question_54.c) | 1/2 |
| 28 | [Q55](Day28/Question_55.c) · [Q56](Day28/Question_56.c) | 4/4 |
| 29 | [Q57](Day29/Question_57.c) · [Q58](Day29/Question_58.c) | 4/4 |
| 30 | [Q59](Day30/Question_59.c) · [Q60](Day30/Question_60.c) | 3/3 |
| 31 | [Q61](Day31/Question_61.c) · [Q62](Day31/Question_62.c) | 3/3 |
| 32 | [Q63](Day32/Question_63.c) · [Q64](Day32/Question_64.c) | 3/3 |
| 33 | [Q65](Day33/Question_65.c) · [Q66](Day33/Question_66.c) | 3/3 |
| 34 | [Q67](Day34/Question_67.c) · [Q68](Day34/Question_68.c) | 2/2 |
| 35 | [Q69](Day35/Question_69.c) · [Q70](Day35/Question_70.c) | 2/2 |
| 36 | [Q71](Day36/Question_71.c) · [Q72](Day36/Question_72.c) | 2/2 |
| 37 | [Q73](Day37/Question_73.c) · [Q74](Day37/Question_74.c) | 2/2 |
| 38 | [Q75](Day38/Question_75.c) · [Q76](Day38/Question_76.c) | 3/3 |
| 39 | [Q77](Day39/Question_77.c) · [Q78](Day39/Question_78.c) | 3/3 |
| 40 | [Q79](Day40/Question_79.c) · [Q80](Day40/Question_80.c) | 2/2 |
| 41 | [Q81](Day41/Question_81.c) · [Q82](Day41/Question_82.c) | 3/3 |
| 42 | [Q83](Day42/Question_83.c) · [Q84](Day42/Question_84.c) | 2/2 |
| 43 | [Q85](Day43/Question_85.c) · [Q86](Day43/Question_86.c) | 3/3 |
| 44 | [Q87](Day44/Question_87.c) · [Q88](Day44/Question_88.c) | 2/2 |
| 45 | [Q89](Day45/Question_89.c) · [Q90](Day45/Question_90.c) | 2/2 |
| 46 | [Q91](Day46/Question_91.c) · [Q92](Day46/Question_92.c) | 2/2 |
| 47 | [Q93](Day47/Question_93.c) · [Q94](Day47/Question_94.c) | 3/3 |
| 48 | [Q95](Day48/Question_95.c) · [Q96](Day48/Question_96.c) | 3/3 |
| 49 | [Q97](Day49/Question_97.c) · [Q98](Day49/Question_98.c) | 2/2 |
| 50 | [Q99](Day50/Question_99.c) · [Q100](Day50/Question_100.c) | 2/2 |
| 51 | [Q101](Day51/Question_101.c) | 3/3 |
| 52 | [Q102](Day52/Question_102.c) | 4/4 |
| 53 | [Q103](Day53/Question_103.c) | 3/3 |
| 54 | [Q104](Day54/Question_104.c) | 3/3 |
| 55 | [Q105](Day55/Question_105.c) | 3/3 |
| 56 | [Q106](Day56/Question_106.c) | 4/4 |
| 57 | [Q107](Day57/Question_107.c) | 4/4 |
| 58 | [Q108](Day58/Question_108.c) | 2/2 |
| 59 | [Q109](Day59/Question_109.c) | 3/3 |
| 60 | [Q110](Day60/Question_110.c) | 2/2 |
| 61 | [Q111](Day61/Question_111.c) | 3/3 |
| 62 | [Q112](Day62/Question_112.c) | 3/3 |
| 63 | [Q113](Day63/Question_113.c) | 2/2 |
| 64 | [Q114](Day64/Question_114.c) | 3/3 |
| 65 | [Q115](Day65/Question_115.c) | 2/2 |
| 66 | [Q116](Day66/Question_116.c) | 3/3 |
| 67 | [Q117](Day67/Question_117.c) | 3/3 |
| 68 | [Q118](Day68/Question_118.c) | 3/3 |
| 69 | [Q119](Day69/Question_119.c) | 3/3 |
| 70 | [Q120](Day70/Question_120.c) | 2/3 |
| 71 | [Q121](Day71/Question_121.c) | 1/1 |
| 72 | [Q122](Day72/Question_122.c) | 1/1 |
| 73 | [Q123](Day73/Question_123.c) | 0/1 |
| 74 | [Q124](Day74/Question_124.c) | 1/1 |
| 75 | [Q125](Day75/Question_125.c) | 1/1 |
| 76 | [Q126](Day76/Question_126.c) | 1/2 |
| 77 | [Q127](Day77/Question_127.c) | 1/1 |
| 78 | [Q128](Day78/Question_128.c) | 1/1 |
| 79 | [Q129](Day79/Question_129.c) | 1/1 |
| 80 | [Q130](Day80/Question_130.c) | 1/1 |
| 81 | [Q131](Day81/Question_131.c) | 1/1 |
| 82 | [Q132](Day82/Question_132.c) | 1/1 |
| 83 | [Q133](Day83/Question_133.c) | 1/1 |
