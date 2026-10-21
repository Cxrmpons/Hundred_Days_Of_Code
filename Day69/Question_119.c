/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.
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
    size_t capacity = 1;
    while (capacity <= (size_t)n) {
        if (capacity > SIZE_MAX / 2)
            return 1;
        capacity *= 2;
    }
    typedef struct {
        int used, value;
    } Entry;
    Entry *seen = calloc(capacity, sizeof(*seen));
    if (!seen)
        return 1;
    int found = 0;
    for (int i = 0; i < n; i++) {
        size_t slot = ((unsigned)values[i] * 2654435761u) & (capacity - 1);
        while (seen[slot].used && seen[slot].value != values[i])
            slot = (slot + 1) & (capacity - 1);
        if (seen[slot].used) {
            printf("%d\n", values[i]);
            found = 1;
            break;
        }
        seen[slot] = (Entry){1, values[i]};
    }
    free(seen);
    free(values);
    free(line);
    if (!found)
        return 1;
    return 0;
}
