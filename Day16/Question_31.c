/*
Q31: Write a program to take a number as input and print its equivalent binary representation.
*/

#include <stdio.h>
static void print_binary(unsigned int n) {
    if (n >= 2)
        print_binary(n / 2);
    putchar('0' + n % 2);
}
int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    if (n < 0)
        putchar('-');
    print_binary(n < 0 ? 0u - (unsigned)n : (unsigned)n);
    putchar('\n');
    return 0;
}
