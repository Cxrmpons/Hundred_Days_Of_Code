/*
Q29: Write a program to calculate the factorial of a number.
*/

#include <limits.h>
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        return 1;
    unsigned long long product = 1;
    for (int i = 2; i <= n; i++) {
        if (product > ULLONG_MAX / (unsigned)i)
            return 1;
        product *= i;
    }
    printf("%llu\n", product);
    return 0;
}
