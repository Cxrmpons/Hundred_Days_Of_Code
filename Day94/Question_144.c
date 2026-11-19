/*
Q144: Write a function that accepts a structure as parameter and prints its members.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    long roll_no;
    double marks;
};

/* The last two fields are the roll number and marks, so names may contain spaces. */
static int parse_student(char *name, struct Student *student)
{
    for (char *p = name; *p != '\0'; ++p) {
        if (!isspace((unsigned char)*p)) {
            continue;
        }

        char extra;
        if (sscanf(p, "%ld%*[ \t]%lf %c", &student->roll_no, &student->marks, &extra) == 2) {
            *p = '\0';
            if (*name == '\0' || strlen(name) >= sizeof student->name || !isfinite(student->marks)) {
                return 0;
            }
            strcpy(student->name, name);
            return 1;
        }
    }
    return 0;
}

static void print_student(struct Student student)
{
    printf("Name: %s | Roll: %ld | Marks: %.15g\n",
           student.name, student.roll_no, student.marks);
}

int main(void)
{
    char row[256];
    struct Student student;
    if (!fgets(row, sizeof row, stdin)) {
        return 1;
    }
    if (!strchr(row, '\n') && !feof(stdin)) {
        return 1;
    }

    char *name = row + strspn(row, " \t");
    if (strncmp(name, "Student:", 8) == 0) {
        name += 8;
        name += strspn(name, " \t");
    }
    if (!parse_student(name, &student)) {
        return 1;
    }
    print_student(student);
    return 0;
}
