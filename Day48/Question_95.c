/*
Q95: Check if one string is a rotation of another.
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
    char *a = read_line(), *b = read_line();
    size_t n = strlen(a);
    int rotation = 0;
    if (n == strlen(b) && n <= (SIZE_MAX - 1) / 2) {
        char *twice = malloc(2 * n + 1);
        if (!twice) {
            free(a);
            free(b);
            return 1;
        }
        memcpy(twice, a, n);
        memcpy(twice + n, a, n + 1);
        rotation = strstr(twice, b) != NULL;
        free(twice);
    }
    puts(rotation ? "Rotation" : "Not rotation");
    free(a);
    free(b);
    return 0;
}
