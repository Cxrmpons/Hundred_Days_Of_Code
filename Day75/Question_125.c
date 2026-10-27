/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
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
    char *path = read_line(), *text = read_line();
    FILE *file = fopen(path, "rb");
    if (!file) {
        free(path);
        free(text);
        return 1;
    }
    int ok = fseek(file, 0, SEEK_END) == 0;
    long length = ok ? ftell(file) : -1;
    int separator = 0;
    if (length < 0)
        ok = 0;
    else if (length > 0) {
        ok = fseek(file, -1, SEEK_END) == 0;
        int last = ok ? fgetc(file) : EOF;
        if (last == EOF)
            ok = 0;
        separator = last != '\n';
    }
    if (fclose(file) != 0)
        ok = 0;
    file = ok ? fopen(path, "ab") : NULL;
    free(path);
    if (!file) {
        free(text);
        return 1;
    }
    if (ok && separator)
        ok = fputc('\n', file) != EOF;
    if (ok)
        ok = fprintf(file, "%s\n", text) >= 0;
    free(text);
    if (fclose(file) != 0 || !ok)
        return 1;
    puts("File updated successfully with appended text.");
    return 0;
}
