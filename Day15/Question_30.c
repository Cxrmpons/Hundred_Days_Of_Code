/*
Q30: Write a program to reverse a given number.
*/

#include <stdio.h>

int main(void) {
    int number;
    if (scanf("%d", &number) != 1)
        return 1;
    long long reversed = 0;
    while (number) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    printf("%lld\n", reversed);
    return 0;
}
