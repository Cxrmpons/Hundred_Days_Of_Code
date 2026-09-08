/*
Q52: Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*


*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int row = 0; row < 5; row++) {
        int height = 5 - 2 * abs(2 - row);
        putchar('\n');
        for (int i = 0; i < height; i++)
            puts("*");
    }
    return 0;
}
