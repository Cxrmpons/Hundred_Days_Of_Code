/*
Q94: Find the longest word in a sentence.
*/

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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
int main(void) {
    char *text = read_line(), *best = text;
    size_t length = 0;
    for (char *p = text; *p;) {
        while (isspace((unsigned char)*p))
            p++;
        char *start = p;
        while (*p && !isspace((unsigned char)*p))
            p++;
        size_t n = (size_t)(p - start);
        if (n > length) {
            best = start;
            length = n;
        }
    }
    fwrite(best, 1, length, stdout);
    putchar('\n');
    free(text);
    return 0;
}
