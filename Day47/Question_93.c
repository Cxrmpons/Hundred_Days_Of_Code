/*
Q93: Check if two strings are anagrams of each other.
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
int main(void) {
    char *a = read_line(), *b = read_line();
    size_t counts[UCHAR_MAX + 1] = {0};
    for (unsigned char *p = (unsigned char *)a; *p; p++)
        counts[*p]++;
    int match = strlen(a) == strlen(b);
    for (unsigned char *p = (unsigned char *)b; match && *p; p++) {
        if (counts[*p] == 0)
            match = 0;
        else
            counts[*p]--;
    }
    puts(match ? "Anagrams" : "Not anagrams");
    free(a);
    free(b);
    return 0;
}
