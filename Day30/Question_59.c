/*
Q59: Count even and odd numbers in an array.
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
    int even = 0;
    for (int i = 0; i < n; i++)
        if (values[i] % 2 == 0)
            even++;
    printf("Even=%d, Odd=%d\n", even, n - even);
    free(values);
    return 0;
}
