/*
Q53: Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int row = 0; row < 9; row++) {
        int width = 9 - 2 * abs(4 - row);
        for (int col = 0; col < width; col++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
