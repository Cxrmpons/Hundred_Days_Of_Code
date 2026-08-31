/*
Q36: Write a program to find the HCF (GCD) of two numbers.
*/

#include <stdio.h>
static long long gcd(long long a, long long b) {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
int main(void) {
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
        return 1;
    printf("%lld\n", gcd(a, b));
    return 0;
}
