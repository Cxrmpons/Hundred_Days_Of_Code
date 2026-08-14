/*
Q1: Write a program to input two numbers and display their sum.
*/

#include <stdio.h>

int main(void) {
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
        return 1;
    printf("Sum = %.15g\n", a + b);
    return 0;
}
