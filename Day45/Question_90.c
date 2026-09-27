/*
Q90: Toggle case of each character in a string.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        putchar(islower(ch) ? toupper(ch) : tolower(ch));
    putchar('\n');
    return 0;
}
