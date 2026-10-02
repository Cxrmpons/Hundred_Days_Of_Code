/*
Q100: Print all sub-strings of a string.
*/

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
    char *text = read_line();
    size_t n = strlen(text);
    for (size_t start = 0; start < n; start++)
        for (size_t end = start; end < n; end++) {
            if (start || end)
                putchar(',');
            fwrite(text + start, 1, end - start + 1, stdout);
        }
    putchar('\n');
    free(text);
    return 0;
}
