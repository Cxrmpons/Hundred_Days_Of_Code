/*
Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
*/

#include <limits.h>
#include <stdio.h>

int main(void) {
    FILE *in = fopen("numbers.txt", "r");
    if (!in)
        return 1;
    int value, scanned;
    long long sum = 0;
    size_t count = 0;
    while ((scanned = fscanf(in, "%d", &value)) == 1) {
        if ((value > 0 && sum > LLONG_MAX - value) || (value < 0 && sum < LLONG_MIN - value)) {
            fclose(in);
            return 1;
        }
        sum += value;
        count++;
    }
    int failed = ferror(in);
    if (fclose(in) != 0 || failed || scanned != EOF || !count)
        return 1;
    printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / count);
    return 0;
}
