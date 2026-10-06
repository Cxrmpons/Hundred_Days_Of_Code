/*
Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
*/

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *read_line(void) {
    size_t length = 0, capacity = 64;
    char *text = malloc(capacity);
    if (!text)
        exit(1);
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length == capacity - 1) {
            if (capacity > SIZE_MAX / 2)
                exit(1);
            capacity *= 2;
            char *larger = realloc(text, capacity);
            if (!larger) {
                free(text);
                exit(1);
            }
            text = larger;
        }
        text[length++] = (char)ch;
    }
    if (ferror(stdin) || (ch == EOF && length == 0)) {
        free(text);
        exit(1);
    }
    if (length && text[length - 1] == '\r')
        length--;
    text[length] = '\0';
    return text;
}
static int read_integer(char **cursor) {
    char *end;
    errno = 0;
    long value = strtol(*cursor, &end, 10);
    if (end == *cursor || errno == ERANGE || value < INT_MIN || value > INT_MAX)
        exit(1);
    *cursor = end;
    return (int)value;
}
static int trailing_integer(char *cursor) {
    while (*cursor && !isdigit((unsigned char)*cursor) && *cursor != '-' && *cursor != '+')
        cursor++;
    int result = read_integer(&cursor);
    if (cursor[strspn(cursor, " \t")])
        exit(1);
    return result;
}
int main(void) {
    char *line = read_line();
    int n = trailing_integer(line);
    free(line);
    if (n < 1)
        return 1;
    // The two inclusive sums are equal exactly when x squared equals the triangular sum.
    long long total = n * ((long long)n + 1) / 2;
    int low = 1, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if ((long long)mid * mid < total)
            low = mid + 1;
        else
            high = mid;
    }
    printf("%d\n", (long long)low * low == total ? low : -1);
    return 0;
}
