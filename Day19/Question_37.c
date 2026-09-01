/*
Q37: Write a program to find the LCM of two numbers.
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
    long long lcm = 0;
    if (a && b)
        lcm = (a / gcd(a, b)) * b;
    printf("%lld\n", lcm < 0 ? -lcm : lcm);
    return 0;
}
