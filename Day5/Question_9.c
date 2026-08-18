/*
Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.
*/

#include <math.h>
#include <stdio.h>

int main(void) {
    double principal, rate, years;
    if (scanf("%lf%lf%lf", &principal, &rate, &years) != 3)
        return 1;
    if (principal < 0 || years < 0 || rate < -100)
        return 1;
    double simple = principal * rate / 100 * years;
    double compound = principal * (pow(1 + rate / 100, years) - 1);
    printf("Simple Interest=%.15g, Compound Interest=%.15g\n", round(simple * 100) / 100,
           round(compound * 100) / 100);
    return 0;
}
