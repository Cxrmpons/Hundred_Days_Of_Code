/*
Q70: Rotate an array to the right by k positions.
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
static void print_array(const int *values, int n) {
    for (int i = 0; i < n; i++)
        printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
}
static void reverse(int *values, int start, int end) {
    while (start < end) {
        int temp = values[start];
        values[start++] = values[end];
        values[end--] = temp;
    }
}
int main(void) {
    int n;
    int *values = read_array(&n);
    int k;
    if (scanf("%d", &k) != 1 || k < 0) {
        free(values);
        return 1;
    }
    if (n) {
        k %= n;
        reverse(values, 0, n - 1);
        reverse(values, 0, k - 1);
        reverse(values, k, n - 1);
    }
    print_array(values, n);
    free(values);
    return 0;
}
