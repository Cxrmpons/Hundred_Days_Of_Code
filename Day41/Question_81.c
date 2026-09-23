/*
Q81: Count characters in a string without using built-in length functions.
*/

#include <stdio.h>

int main(void) {
    size_t count = 0;
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        count++;
    if (ferror(stdin))
        return 1;
    printf("%zu\n", count);
    return 0;
}
