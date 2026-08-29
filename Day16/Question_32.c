/*
Q32: Write a program to check if a number is a palindrome.
*/

#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    long long reversed = 0;
    for (int digits = n; digits > 0; digits /= 10)
        reversed = reversed * 10 + digits % 10;
    puts(n == reversed ? "Palindrome" : "Not palindrome");
    return 0;
}
