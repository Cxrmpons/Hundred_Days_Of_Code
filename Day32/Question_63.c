/*
Q63: Merge two arrays.
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int n, m;
    int *first = read_array(&n), *second = read_array(&m);
    if (n > INT_MAX - m) {
        free(first);
        free(second);
        return 1;
    }
    int *merged = realloc(first, ((size_t)n + m + 1) * sizeof(*merged));
    if (!merged) {
        free(first);
        free(second);
        return 1;
    }
    memcpy(merged + n, second, (size_t)m * sizeof(*second));
    print_array(merged, n + m);
    free(merged);
    free(second);
    return 0;
}
