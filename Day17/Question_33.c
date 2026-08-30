/*
Q33: Write a program to check if a number is an Armstrong number.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        return 1;
    int count = 1;
    for (int v = n; v >= 10; v /= 10)
        count++;
    long long sum = 0;
    for (int v = n; v; v /= 10) {
        long long power = 1;
        for (int i = 0; i < count; i++)
            power *= v % 10;
        sum += power;
    }
    puts(sum == n ? "Armstrong" : "Not Armstrong");
    return 0;
}
