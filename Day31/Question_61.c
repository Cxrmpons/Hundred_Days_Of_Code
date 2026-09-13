/*
Q61: Search for an element in an array using linear search.
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
    int target;
    if (scanf("%d", &target) != 1) {
        free(values);
        return 1;
    }
    int i = 0;
    while (i < n && values[i] != target)
        i++;
    if (i == n)
        puts("-1");
    else
        printf("Found at index %d\n", i);
    free(values);
    return 0;
}
