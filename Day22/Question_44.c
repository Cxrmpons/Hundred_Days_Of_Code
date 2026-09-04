/*
Q44: Write a program to find the sum of the series: 1 + 3/4 + 5/6 + 7/8 + … up to n terms.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        return 1;
    double sum = n > 0 ? 1.0 : 0.0;
    for (long long i = 2; i <= n; i++)
        sum += (2.0 * i - 1) / (2.0 * i);
    printf("Approximate sum: %.1f\n", sum);
    return 0;
}
