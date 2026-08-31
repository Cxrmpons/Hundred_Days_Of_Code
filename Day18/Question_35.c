/*
Q35: Write a program to print all factors of a given number.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 1)
        return 1;
    int i = 1;
    for (; i <= n / i; i++)
        if (n % i == 0)
            printf("%s%d", i == 1 ? "" : " ", i);
    for (i--; i >= 1; i--)
        if (n % i == 0 && i != n / i)
            printf(" %d", n / i);
    putchar('\n');
    return 0;
}
