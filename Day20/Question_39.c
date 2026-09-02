/*
Q39: Write a program to find the product of odd digits of a number.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    long long magnitude = n;
    if (magnitude < 0)
        magnitude = -magnitude;
    long long product = 1, place = 1;
    int count = 0;
    for (long long v = magnitude; v; v /= 10) {
        int digit = v % 10;
        if (digit % 2) {
            product *= digit;
            count++;
        }
        if (v >= 10)
            place *= 10;
    }
    printf("%lld (", product);
    if (!count)
        printf("no odd digits, assume 1");
    while (place) {
        int digit = magnitude / place % 10;
        if (digit % 2) {
            printf("%d", digit);
            if (--count)
                putchar('*');
        }
        place /= 10;
    }
    puts(")");
    return 0;
}
