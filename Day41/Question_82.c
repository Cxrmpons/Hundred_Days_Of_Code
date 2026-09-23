/*
Q82: Print each character of a string on a new line.
*/

#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        putchar(ch);
        putchar('\n');
    }
    if (ferror(stdin))
        return 1;
    return 0;
}
