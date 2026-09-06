/*
Q48: Write a program to print the following pattern:
1
12
123
1234
12345
*/

#include <stdio.h>

int main(void) {
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++)
            printf("%d", col);
        putchar('\n');
    }
    return 0;
}
