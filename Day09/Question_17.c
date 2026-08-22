/*
Q17: Write a program to find the roots of a quadratic equation and categorize them.
*/

#include <math.h>
#include <stdio.h>

int main(void) {
    double a, b, c;
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
        return 1;
    if (a == 0)
        return 1;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        puts("Roots are complex");
    else if (discriminant == 0)
        printf("Roots are real and same: %g\n", -b / (2 * a));
    else {
        double q = -0.5 * (b + copysign(sqrt(discriminant), b));
        double first = q / a, second = c / q;
        printf("Roots are real and different: %g, %g\n", b < 0 ? first : second,
               b < 0 ? second : first);
    }
    return 0;
}
