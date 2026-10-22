/*
Q120: Write a program to take a string input. Change it to sentence case.
*/

#include <ctype.h>
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
int main(void) {
    char *line = read_line(), *text = line;
    if (strncmp(text, "str = ", 6) == 0)
        text += 6;
    int word_start = 1;
    for (unsigned char *p = (unsigned char *)text; *p; p++) {
        putchar(word_start ? toupper(*p) : *p);
        word_start = isspace(*p);
    }
    putchar('\n');
    free(line);
    return 0;
}
