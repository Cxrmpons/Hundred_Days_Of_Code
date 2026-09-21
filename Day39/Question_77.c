/*
Q77: Check if the elements on the diagonal of a matrix are distinct.
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
static int cell(Matrix a, int row, int col) { return a.data[row * a.cols + col]; }
int main(void) {
    Matrix a = read_matrix();
    int size = a.rows < a.cols ? a.rows : a.cols, distinct = 1;
    for (int i = 1; i < size && distinct; i++)
        for (int j = 0; j < i; j++)
            if (cell(a, i, i) == cell(a, j, j)) {
                distinct = 0;
                break;
            }
    puts(distinct ? "True" : "False");
    free(a.data);
    return 0;
}
