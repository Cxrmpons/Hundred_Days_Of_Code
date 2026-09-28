/*
Q91: Remove all vowels from a string.
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        if (!strchr("aeiouAEIOU", ch))
            putchar(ch);
    putchar('\n');
    return 0;
}
