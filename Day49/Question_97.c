/*
Q97: Print the initials of a name.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int ch, new_word = 1;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isspace(ch))
            new_word = 1;
        else if (new_word) {
            printf("%c.", toupper(ch));
            new_word = 0;
        }
    }
    putchar('\n');
    return 0;
}
