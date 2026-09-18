/*
Q72: Find the sum of all elements in a matrix.
*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int rows, cols;
    int *data;
} Matrix;
static Matrix read_matrix(void) {
    Matrix a;
    if (scanf("%d%d", &a.rows, &a.cols) != 2 || a.rows < 1 || a.cols < 1 ||
        a.rows > INT_MAX / a.cols)
        exit(1);
    size_t cells = (size_t)a.rows * a.cols;
    if (cells > SIZE_MAX / sizeof(int))
        exit(1);
    a.data = malloc(cells * sizeof(*a.data));
    if (!a.data)
        exit(1);
    for (size_t i = 0; i < cells; i++)
        if (scanf("%d", &a.data[i]) != 1) {
            free(a.data);
            exit(1);
        }
    return a;
}
int main(void) {
    Matrix a = read_matrix();
    long long sum = 0;
    for (int i = 0; i < a.rows * a.cols; i++)
        sum += a.data[i];
    printf("%lld\n", sum);
    free(a.data);
    return 0;
}
