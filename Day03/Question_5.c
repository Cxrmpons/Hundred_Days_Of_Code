/*
Q5: Write a program to convert temperature from Celsius to Fahrenheit.
*/

#include <stdio.h>

int main(void) {
    double celsius;
    if (scanf("%lf", &celsius) != 1)
        return 1;
    printf("Fahrenheit=%g\n", celsius * 1.8 + 32);
    return 0;
}
