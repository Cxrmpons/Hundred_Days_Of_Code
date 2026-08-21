/*
Q15: Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1)
        return 1;
    unsigned char c = (unsigned char)ch;
    if (isupper(c))
        puts("Uppercase alphabet");
    else if (islower(c))
        puts("Lowercase alphabet");
    else if (isdigit(c))
        puts("Digit");
    else
        puts("Special character");
    return 0;
}
