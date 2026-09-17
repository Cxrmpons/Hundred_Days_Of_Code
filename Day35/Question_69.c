/*
Q69: Find the second largest element in an array.
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
static int *read_array(int *n) {
    if (scanf("%d", n) != 1 || *n < 0 || (size_t)*n >= SIZE_MAX / sizeof(int))
        exit(1);
    int *values = malloc(((size_t)*n + 1) * sizeof(*values));
    if (!values)
        exit(1);
    for (int i = 0; i < *n; i++)
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            exit(1);
        }
    return values;
}
int main(void) {
    int n;
    int *values = read_array(&n);
    long long largest = -(long long)INT_MAX - 2, second = largest;
    for (int i = 0; i < n; i++) {
        if (values[i] > largest) {
            second = largest;
            largest = values[i];
        } else if (values[i] < largest && values[i] > second)
            second = values[i];
    }
    free(values);
    if (second < INT_MIN)
        return 1;
    printf("%lld\n", second);
    return 0;
}
