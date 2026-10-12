/*
Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.
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
    int *indices = malloc((size_t)n * sizeof(*indices));
    if (!indices)
        return 1;
    int front = 0, end = 0;
    for (int i = 0; i < n; i++) {
        if (front < end && indices[front] <= i - k)
            front++;
        while (front < end && values[indices[end - 1]] <= values[i])
            end--;
        indices[end++] = i;
        if (i >= k - 1)
            printf("%s%d", i == k - 1 ? "" : " ", values[indices[front]]);
    }
    putchar('\n');
    free(indices);
    free(values);
    free(line);
    return 0;
}
