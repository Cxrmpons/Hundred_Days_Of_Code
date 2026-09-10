/*
Q55: Write a program to print all the prime numbers from 1 to n.
*/

#include <stdio.h>
static int is_prime(int n) {
    if (n < 2)
        return 0;
    for (int divisor = 2; divisor <= n / divisor; divisor++)
        if (n % divisor == 0)
            return 0;
    return 1;
}
int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        return 1;
    for (long long v = 2; v <= n; v++)
        if (is_prime((int)v))
            printf("%s%lld", v == 2 ? "" : " ", v);
    putchar('\n');
    return 0;
}
