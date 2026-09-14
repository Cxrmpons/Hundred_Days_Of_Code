/*
Q64: Find the digit that occurs the most times in an integer number.
*/

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    int count[10] = {0};
    int c = getchar();
    if (c == '-' || c == '+')
        c = getchar();
    if (!isdigit(c))
        return 1;
    while (isdigit(c)) {
        if (count[c - '0'] == INT_MAX)
            return 1;
        count[c - '0']++;
        c = getchar();
    }
    if (c != EOF && !isspace(c))
        return 1;
    int best = 0;
    for (int i = 1; i < 10; i++)
        if (count[i] > count[best])
            best = i;
    printf("%d\n", best);
    return 0;
}
