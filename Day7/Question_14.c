/*
Q14: Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1)
        return 1;
    if (!isalpha((unsigned char)ch))
        return 1;
    if (strchr("aeiouAEIOU", ch))
        puts("Vowel");
    else
        puts("Consonant");
    return 0;
}
