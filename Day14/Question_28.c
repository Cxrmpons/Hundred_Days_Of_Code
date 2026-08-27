/*
Q28: Write a program to print the product of even numbers from 1 to n.
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
    for (int i = 2; i <= n; i += 2) {
        if (product > ULLONG_MAX / (unsigned)i)
            return 1;
        product *= i;
    }
    printf("%llu", product);
    if (n >= 2) {
        printf(" (");
        for (int i = 2; i <= n; i += 2)
            printf("%s%d", i == 2 ? "" : " * ", i);
        putchar(')');
    }
    putchar('\n');
    return 0;
}
