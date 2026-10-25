/*
Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
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
    char *path = read_line();
    FILE *in = fopen(path, "r");
    free(path);
    if (!in)
        return 1;
    size_t characters = 0, words = 0, lines = 0;
    int in_word = 0, ch, last = '\n';
    while ((ch = fgetc(in)) != EOF) {
        characters++;
        if (ch == '\n')
            lines++;
        if (isspace(ch))
            in_word = 0;
        else if (!in_word) {
            words++;
            in_word = 1;
        }
        last = ch;
    }
    if (last != '\n')
        lines++;
    int failed = ferror(in);
    if (fclose(in) != 0 || failed)
        return 1;
    printf("Characters: %zu\nWords: %zu\nLines: %zu\n", characters, words, lines);
    return 0;
}
