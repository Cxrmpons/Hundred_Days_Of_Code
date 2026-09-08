/*
Q51: Write a program to print the following pattern:
    5
   45
  345
 2345
12345
*/

#include <stdio.h>

int main(void) {
    for (int start = 5; start >= 1; start--) {
        for (int space = 1; space < start; space++)
            putchar(' ');
        for (int value = start; value <= 5; value++)
            printf("%d", value);
        putchar('\n');
    }
    return 0;
}
