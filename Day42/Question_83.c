/*
Q83: Count vowels and consonants in a string.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    size_t vowels = 0, consonants = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isalpha(ch)) {
            if (strchr("aeiou", tolower(ch)))
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels=%zu, Consonants=%zu\n", vowels, consonants);
    return 0;
}
