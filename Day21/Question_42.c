/*
Q42: Write a program to check if a number is a perfect number.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    long long sum = n > 1 ? 1 : 0;
    for (int d = 2; d <= n / d; d++)
        if (n % d == 0) {
            sum += d;
            if (d != n / d)
                sum += n / d;
        }
    puts(n > 1 && sum == n ? "Perfect number" : "Not perfect number");
    return 0;
}
