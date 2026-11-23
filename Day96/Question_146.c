/*
Q146: Create Employee structure with nested Date structure for joining date and print details.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[100];
    long id;
    struct Date joining_date;
};

static int valid_date(struct Date date)
{
    const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.year < 1 || date.month < 1 || date.month > 12) {
        return 0;
    }
    int limit = month_days[date.month - 1];
    if (date.month == 2 && date.year % 4 == 0 &&
        (date.year % 100 != 0 || date.year % 400 == 0)) {
        ++limit;
    }
    return date.day >= 1 && date.day <= limit;
}

int main(void)
{
    struct Employee employee;
    struct Date *date = &employee.joining_date;
    if (scanf(" Employee: %99[^|]| ID: %ld | Joining Date: %d %d %d",
              employee.name, &employee.id, &date->day, &date->month, &date->year) != 5) {
        return 1;
    }

    size_t length = strlen(employee.name);
    while (length > 0 && isspace((unsigned char)employee.name[length - 1])) {
        employee.name[--length] = '\0';
    }
    if (length == 0 || !valid_date(*date)) {
        return 1;
    }

    printf("Name: %s | ID: %ld | Joining Date: %02d/%02d/%04d\n",
           employee.name, employee.id, date->day, date->month, date->year);
    return 0;
}
