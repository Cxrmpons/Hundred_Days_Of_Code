/*
Q60: Count positive, negative, and zero elements in an array.
*/

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
    int positive = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        positive += values[i] > 0;
        negative += values[i] < 0;
    }
    printf("Positive=%d, Negative=%d, Zero=%d\n", positive, negative, n - positive - negative);
    free(values);
    return 0;
}
