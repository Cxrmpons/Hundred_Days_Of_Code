/*
Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

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
int main(void) {
    char *line = read_line(), *cursor = line;
    int n;
    int *values = parse_array(&cursor, &n);
    long long *answer = calloc((size_t)n + 1, sizeof(*answer));
    if (!answer)
        return 1;
    long long prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= values[i];
    }
    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= values[i];
    }
    putchar('[');
    for (int i = 0; i < n; i++)
        printf("%s%lld", i ? "," : "", answer[i]);
    puts("]");
    free(answer);
    free(values);
    free(line);
    return 0;
}
