/*
Q133: Create an enum for months and print how many days each month has.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main(void) {
    const char *names[] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };
    char input[32];
    if (scanf("%31s", input) != 1)
        return 1;
    for (size_t i = 0; input[i] != '\0'; i++)
        input[i] = (char)toupper((unsigned char)input[i]);

    enum Month month;
    for (month = JAN; month <= DEC; month++) {
        if (strcmp(input, names[month]) == 0 ||
            (strlen(input) == 3 && strncmp(input, names[month], 3) == 0))
            break;
    }
    if (month > DEC)
        return 1;

    switch (month) {
    case FEB:
        puts("28 or 29 days");
        break;
    case APR:
    case JUN:
    case SEP:
    case NOV:
        puts("30 days");
        break;
    default:
        puts("31 days");
        break;
    }
    return 0;
}
