/*
Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
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
static char *quoted_string(char **cursor) {
    char *start = strchr(*cursor, '"');
    if (!start)
        exit(1);
    char *end = strchr(++start, '"');
    if (!end)
        exit(1);
    *end = '\0';
    *cursor = end + 1;
    return start;
}
int main(void) {
    char *line = read_line(), *cursor = line, *s = quoted_string(&cursor),
         *t = quoted_string(&cursor);
    size_t count[26] = {0};
    for (char *p = s; *p; p++) {
        if (*p < 'a' || *p > 'z')
            return 1;
        count[*p - 'a']++;
    }
    int match = strlen(s) == strlen(t);
    for (char *p = t; *p; p++) {
        if (*p < 'a' || *p > 'z')
            return 1;
        if (!count[*p - 'a'])
            match = 0;
        else
            count[*p - 'a']--;
    }
    puts(match ? "Anagram" : "Not Anagram");
    free(line);
    return 0;
}
