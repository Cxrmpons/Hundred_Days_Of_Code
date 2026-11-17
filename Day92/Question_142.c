/*
Q142: Store details of 5 students in an array of structures and print all.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

enum { STUDENT_COUNT = 5 };

struct Student {
    char name[80];
    int roll_no;
    double marks;
};

/* Read one name, roll number and mark per line. Commas allow names with spaces. */
static int read_student(struct Student *student) {
    char line[160], extra;
    if (!fgets(line, sizeof line, stdin))
        return 0;
    if (strchr(line, '\n') == NULL && !feof(stdin))
        return 0;

    const char *format = strchr(line, ',')
        ? " %79[^,], %d , %lf %c"
        : " %79s%*[ \t]%d%*[ \t]%lf %c";
    if (sscanf(line, format, student->name, &student->roll_no,
               &student->marks, &extra) != 3 || !isfinite(student->marks))
        return 0;

    size_t length = strlen(student->name);
    while (length > 0 && isspace((unsigned char)student->name[length - 1]))
        student->name[--length] = '\0';
    return length != 0;
}

int main(void) {
    struct Student students[STUDENT_COUNT];

    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (!read_student(&students[i]))
            return 1;
    }

    puts("Name\tRoll\tMarks");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s\t%d\t%.15g\n", students[i].name, students[i].roll_no,
               students[i].marks);
    }
    return 0;
}
