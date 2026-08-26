/*
Q25: Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
*/

#include <math.h>
#include <stdio.h>

int main(void) {
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
        return 1;
    char op;
    if (scanf(" %c", &op) != 1)
        return 1;
    double answer;
    switch (op) {
    case '+':
        answer = a + b;
        break;
    case '-':
        answer = a - b;
        break;
    case '*':
        answer = a * b;
        break;
    case '/':
        if (!b)
            return 1;
        answer = a / b;
        break;
    case '%':
        if (!b || trunc(a) != a || trunc(b) != b)
            return 1;
        answer = fmod(a, b);
        break;
    default:
        return 1;
    }
    printf("%g\n", answer);
    return 0;
}
