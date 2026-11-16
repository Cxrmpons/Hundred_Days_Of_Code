/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct Student {
    char name[80];
    int roll_no;
    double marks;
};

int main(void) {
    struct Student student;

    if (scanf(" Name: %79[^\r\n] Roll: %d Marks: %lf",
              student.name, &student.roll_no, &student.marks) != 3 ||
        !isfinite(student.marks))
        return 1;

    size_t length = strlen(student.name);
    while (length > 0 && isspace((unsigned char)student.name[length - 1]))
        student.name[--length] = '\0';

    printf("Name: %s | Roll: %d | Marks: %.15g\n",
           student.name, student.roll_no, student.marks);
    return 0;
}
