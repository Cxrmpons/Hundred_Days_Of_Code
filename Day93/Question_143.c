/*
Q143: Find and print the student with the highest marks.
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

/* Rows may be comma-separated as in the example, or entered one per line. */
static int read_student(struct Student *student)
{
    char row[256];
    while (scanf(" %255[^,\n]", row) == 1) {
        int delimiter = getchar();
        if (delimiter != ',' && delimiter != '\n' && delimiter != EOF) {
            return 0;
        }

        char *name = row;
        if (strncmp(name, "students:", 9) == 0) {
            name += 9;
        } else if (strncmp(name, "student:", 8) == 0) {
            name += 8;
        }
        name += strspn(name, " \t\r");
        if (*name != '\0') {
            return parse_student(name, student);
        }
    }
    return 0;
}

int main(void)
{
    int count;
    struct Student top;
    if (scanf("%d", &count) != 1 || count < 1 || !read_student(&top)) {
        return 1;
    }
    for (int i = 1; i < count; ++i) {
        struct Student current;
        if (!read_student(&current)) {
            return 1;
        }
        if (current.marks > top.marks) {
            top = current;
        }
    }

    printf("Topper: %s (Marks: %.15g)\n", top.name, top.marks);
    return 0;
}
