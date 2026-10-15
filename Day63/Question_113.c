/*
Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.
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
static int *parse_array(char **cursor, int *count) {
    char *p = strchr(*cursor, '[');
    if (!p)
        exit(1);
    p += 1;
    p += strspn(p, " \t");
    if (*p == ']') {
        char *next = p + 1;
        next += strspn(next, " \t");
        if (*next == '=') {
            next++;
            next += strspn(next, " \t");
            if (*next == '[')
                p = next + 1;
        }
    }
    int n = 0;
    size_t capacity = 8;
    int *values = malloc(capacity * sizeof(*values));
    if (!values)
        exit(1);
    p += strspn(p, " \t");
    while (*p != ']') {
        if (n == INT_MAX)
            exit(1);
        if ((size_t)n == capacity) {
            if (capacity > SIZE_MAX / 2 / sizeof(*values))
                exit(1);
            capacity *= 2;
            int *larger = realloc(values, capacity * sizeof(*values));
            if (!larger)
                exit(1);
            values = larger;
        }
        values[n++] = read_integer(&p);
        p += strspn(p, " \t");
        if (*p == ']')
            break;
        if (*p++ != ',')
            exit(1);
        p += strspn(p, " \t");
        if (*p == ']')
            exit(1);
    }
    *count = n;
    *cursor = p + 1;
    return values;
}
static int trailing_integer(char *cursor) {
    while (*cursor && !isdigit((unsigned char)*cursor) && *cursor != '-' && *cursor != '+')
        cursor++;
    int result = read_integer(&cursor);
    if (cursor[strspn(cursor, " \t")])
        exit(1);
    return result;
}
static int compare(const void *a, const void *b) {
    int left = *(const int *)a, right = *(const int *)b;
    return (left > right) - (left < right);
}
int main(void) {
    char *line = read_line(), *cursor = line;
    int n;
    int *values = parse_array(&cursor, &n);
    int k = trailing_integer(cursor);
    if (k < 1 || k > n) {
        free(values);
        free(line);
        return 1;
    }
    qsort(values, (size_t)n, sizeof(*values), compare);
    printf("%d\n", values[k - 1]);
    free(values);
    free(line);
    return 0;
}
