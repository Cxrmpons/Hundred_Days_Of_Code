/*
Q86: Check if a string is a palindrome.
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
    int palindrome = 1;
    for (size_t i = 0; i < n / 2; i++)
        if (text[i] != text[n - 1 - i]) {
            palindrome = 0;
            break;
        }
    puts(palindrome ? "Palindrome" : "Not palindrome");
    free(text);
    return 0;
}
