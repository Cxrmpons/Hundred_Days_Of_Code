/*
Q80: Multiply two matrices.
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
    Matrix a = read_matrix(), b = read_matrix();
    if (a.cols != b.rows) {
        free(a.data);
        free(b.data);
        return 1;
    }
    for (int r = 0; r < a.rows; r++) {
        for (int c = 0; c < b.cols; c++) {
            long long sum = 0;
            for (int k = 0; k < a.cols; k++) {
                long long product = (long long)cell(a, r, k) * cell(b, k, c);
                if ((product > 0 && sum > LLONG_MAX - product) ||
                    (product < 0 && sum < LLONG_MIN - product)) {
                    free(a.data);
                    free(b.data);
                    return 1;
                }
                sum += product;
            }
            printf("%s%lld", c ? " " : "", sum);
        }
        putchar('\n');
    }
    free(a.data);
    free(b.data);
    return 0;
}
