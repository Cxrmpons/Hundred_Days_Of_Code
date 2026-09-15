/*
Q66: Insert an element in a sorted array at the appropriate position.
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
static void print_array(const int *values, int n) {
    for (int i = 0; i < n; i++)
        printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
}
int main(void) {
    int n;
    int *values = read_array(&n);
    int value;
    if (n == INT_MAX || scanf("%d", &value) != 1) {
        free(values);
        return 1;
    }
    int index = n;
    while (index > 0 && values[index - 1] > value) {
        values[index] = values[index - 1];
        index--;
    }
    values[index] = value;
    print_array(values, n + 1);
    free(values);
    return 0;
}
