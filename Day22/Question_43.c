/*
Q43: Write a program to check if a number is a strong number.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        return 1;
    int sum = 0, v = n;
    do {
        int factorial = 1;
        for (int k = 2; k <= v % 10; k++)
            factorial *= k;
        sum += factorial;
        v /= 10;
    } while (v);
    puts(sum == n ? "Strong number" : "Not strong number");
    return 0;
}
