/*
Q38: Write a program to find the sum of digits of a number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    int sum = 0;
    while (n) {
        sum += abs(n % 10);
        n /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
