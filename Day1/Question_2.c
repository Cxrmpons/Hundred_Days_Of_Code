/*
Q2: Write a program to input two numbers and display their sum, difference, product, and quotient.
*/

#include <stdio.h>

int main(void) {
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
        return 1;
    if (!b) {
        fputs("Division by zero\n", stderr);
        return 1;
    }
    printf("Sum=%lld, Diff=%lld, Product=%lld, Quotient=%lld\n", (long long)a + b,
           (long long)a - b, (long long)a * b, (long long)a / b);
    return 0;
}
