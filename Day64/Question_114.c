/*
Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
*/

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
static char *quoted_string(char **cursor) {
    char *start = strchr(*cursor, '"');
    if (!start)
        exit(1);
    char *end = strchr(++start, '"');
    if (!end)
        exit(1);
    *end = '\0';
    *cursor = end + 1;
    return start;
}
int main(void) {
    char *line = read_line(), *cursor = line, *text = quoted_string(&cursor);
    size_t next[UCHAR_MAX + 1] = {0}, start = 0, longest = 0;
    for (size_t i = 0; text[i]; i++) {
        unsigned char c = (unsigned char)text[i];
        if (next[c] > start)
            start = next[c];
        if (i - start + 1 > longest)
            longest = i - start + 1;
        next[c] = i + 1;
    }
    printf("%zu\n", longest);
    free(line);
    return 0;
}
