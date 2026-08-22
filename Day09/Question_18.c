/*
Q18: Write a program that accepts a percentage (0-100) and assigns a grade based on the following criteria: 
90-100: Grade A 
80-89: Grade B 
70-79: Grade C 
60-69: Grade D 
below 60: Grade F.
*/

#include <stdio.h>

int main(void) {
    double score;
    if (scanf("%lf", &score) != 1)
        return 1;
    if (score < 0 || score > 100)
        return 1;
    char grade = 'F';
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    printf("Grade %c\n", grade);
    return 0;
}
