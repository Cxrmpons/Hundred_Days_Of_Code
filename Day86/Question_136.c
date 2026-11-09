/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
*/

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Operation { ADD, SUBTRACT, MULTIPLY };

static int read_integer(long long *value) {
    char token[64];
    if (scanf("%63s", token) != 1)
        return 0;
    int next = getchar();
    if (next != EOF && !isspace((unsigned char)next))
        return 0;

    char *end;
    errno = 0;
    *value = strtoll(token, &end, 10);
    return *end == '\0' && errno != ERANGE;
}

/* Divide the limit first to avoid computing an out-of-range product. */
static int product_fits(long long a, long long b) {
    if (a > 0)
        return b <= LLONG_MAX / a && b >= LLONG_MIN / a;
    if (a < 0 && b > 0)
        return a >= LLONG_MIN / b;
    if (a < 0 && b < 0)
        return a >= LLONG_MAX / b;
    return 1;
}

int main(void) {
    char command[16];
    enum Operation operation;
    if (scanf("%15s", command) != 1)
        return 1;
    if (strcmp(command, "ADD") == 0)
        operation = ADD;
    else if (strcmp(command, "SUBTRACT") == 0)
        operation = SUBTRACT;
    else if (strcmp(command, "MULTIPLY") == 0)
        operation = MULTIPLY;
    else
        return 1;

    long long a, b;
    if (!read_integer(&a) || !read_integer(&b))
        return 1;

    long long result;
    switch (operation) {
    case ADD:
        if ((b > 0 && a > LLONG_MAX - b) || (b < 0 && a < LLONG_MIN - b))
            return 1;
        result = a + b;
        break;
    case SUBTRACT:
        if ((b > 0 && a < LLONG_MIN + b) || (b < 0 && a > LLONG_MAX + b))
            return 1;
        result = a - b;
        break;
    case MULTIPLY:
        if (!product_fits(a, b))
            return 1;
        result = a * b;
        break;
    default:
        return 1;
    }
    printf("%lld\n", result);
    return 0;
}
