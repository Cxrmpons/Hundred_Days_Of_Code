/*
Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
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
    char *path = read_line();
    FILE *in = fopen(path, "r");
    free(path);
    if (!in)
        return 1;
    size_t vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(in)) != EOF)
        if (isalpha(ch)) {
            if (strchr("aeiou", tolower(ch)))
                vowels++;
            else
                consonants++;
        }
    int failed = ferror(in);
    if (fclose(in) != 0 || failed)
        return 1;
    printf("Vowels: %zu\nConsonants: %zu\n", vowels, consonants);
    return 0;
}
