/*
Q56: Read and print elements of a one-dimensional array.
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
int main(void) {
    int n;
    int *values = read_array(&n);
    print_array(values, n);
    free(values);
    return 0;
}
