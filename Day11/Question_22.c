/*
Q22: Write a program to find profit or loss percentage given cost price and selling price.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double cost, selling;
    if (scanf("%lf%lf", &cost, &selling) != 2)
        return 1;
    if (cost <= 0 || selling < 0)
        return 1;
    if (selling == cost)
        puts("No Profit No Loss");
    else
        printf("%s %g%%\n", selling > cost ? "Profit" : "Loss",
               100 * fabs(selling - cost) / cost);
    return 0;
}
