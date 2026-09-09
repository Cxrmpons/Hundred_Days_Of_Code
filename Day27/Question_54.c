/*
Q54: Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int row = 0; row < 7; row++) {
        int indent = abs(3 - row);
        for (int i = 0; i < indent; i++)
            putchar(' ');
        for (int i = 0; i < 7 - 2 * indent; i++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
