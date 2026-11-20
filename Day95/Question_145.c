/*
Q145: Return a structure containing top student's details from a function.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

static struct Student top_student(const struct Student students[], int count)
{
    int best = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > students[best].marks) {
            best = i;
        }
    }
    return students[best];
}

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 1) {
        return 1;
    }
    struct Student *students = calloc((size_t)count, sizeof *students);
    if (students == NULL) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (!read_student(&students[i])) {
            free(students);
            return 1;
        }
    }

    struct Student top = top_student(students, count);
    printf("Top Student: %s | Roll: %ld | Marks: %.15g\n", top.name, top.roll_no, top.marks);
    free(students);
    return 0;
}
