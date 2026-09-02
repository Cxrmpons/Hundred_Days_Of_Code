/*
Q40: Write a program to find the 1’s complement of a binary number and print it.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int digit = getchar();
    if (digit != '0' && digit != '1')
        return 1;
    do {
        putchar(digit == '1' ? '0' : '1');
        digit = getchar();
    } while (digit == '0' || digit == '1');
    if (digit != EOF && !isspace(digit))
        return 1;
    putchar('\n');
    return 0;
}
