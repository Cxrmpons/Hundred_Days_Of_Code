/*
Q98: Print initials of a name with the surname displayed in full.
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
    char *name = read_line(), *previous = NULL;
    int initials = 0;
    for (char *p = name; *p;) {
        while (isspace((unsigned char)*p))
            p++;
        if (!*p)
            break;
        if (previous) {
            printf("%c.", toupper((unsigned char)*previous));
            initials = 1;
        }
        previous = p;
        while (*p && !isspace((unsigned char)*p))
            p++;
        if (*p)
            *p++ = '\0';
    }
    if (previous)
        printf("%s%s", initials ? " " : "", previous);
    putchar('\n');
    free(name);
    return 0;
}
