/*
Q92: Find the first repeating lowercase alphabet in a string.
*/

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
    char *text = read_line();
    size_t frequency[26] = {0};
    for (char *p = text; *p; p++)
        if (*p >= 'a' && *p <= 'z')
            frequency[*p - 'a']++;
    for (char *p = text; *p; p++)
        if (*p >= 'a' && *p <= 'z' && frequency[*p - 'a'] > 1) {
            printf("%c\n", *p);
            free(text);
            return 0;
        }
    free(text);
    puts("-1");
    return 0;
}
