/*
Q46: Write a program to print the following pattern:
*****
*****
*****
*****
*****
*/

#include <stdio.h>

int main(void) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
