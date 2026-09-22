/*
Q79: Perform diagonal traversal of a matrix.
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
    for (long long d = 0; d < (long long)a.rows + a.cols - 1; d++) {
        int top = d < a.cols ? 0 : (int)(d - a.cols + 1),
            bottom = d < a.rows ? (int)d : a.rows - 1;
        for (int offset = 0; offset <= bottom - top; offset++) {
            int row = d % 2 ? top + offset : bottom - offset;
            printf("%s%d", (d || offset) ? " " : "", cell(a, row, (int)(d - row)));
        }
    }
    putchar('\n');
    free(a.data);
    return 0;
}
