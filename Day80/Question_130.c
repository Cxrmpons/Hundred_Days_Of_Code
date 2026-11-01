/*
Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
*/

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[100];
    int roll;
    double marks;
} Student;
int main(void) {
    int n = 0;
    int labeled = scanf("%d", &n) != 1;
    if (n < 0)
        return 1;
    // Validate the input records before replacing the data file.
    Student *students = calloc((size_t)n + 1, sizeof(*students));
    if (!students)
        return 1;
    if (labeled) {
        int separator;
        do {
            Student s;
            if (scanf(" Student %*d → Name: %99[^,], Roll: %d, Marks: %lf", s.name, &s.roll,
                      &s.marks) != 3 ||
                s.roll < 0 || !isfinite(s.marks) || strpbrk(s.name, " \t\n") || n == INT_MAX) {
                free(students);
                return 1;
            }
            Student *more = realloc(students, ((size_t)n + 1) * sizeof(*more));
            if (!more) {
                free(students);
                return 1;
            }
            students = more;
            students[n++] = s;
            do {
                separator = getchar();
            } while (separator != EOF && isspace(separator));
        } while (separator == ';');
        if (separator != EOF) {
            free(students);
            return 1;
        }
    } else
        for (int i = 0; i < n; i++) {
            Student *s = &students[i];
            if (scanf("%99s%d%lf", s->name, &s->roll, &s->marks) != 3 || s->roll < 0 ||
                !isfinite(s->marks)) {
                free(students);
                return 1;
            }
        }
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        free(students);
        return 1;
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
        Student s = students[i];
        if (fprintf(file, "%s %d %.17g\n", s.name, s.roll, s.marks) < 0) {
            ok = 0;
            break;
        }
    }
    free(students);
    if (fclose(file) != 0 || !ok)
        return 1;
    file = fopen("students.txt", "r");
    if (!file)
        return 1;
    Student s;
    int fields;
    while ((fields = fscanf(file, "%99s%d%lf", s.name, &s.roll, &s.marks)) == 3)
        printf("Name: %s | Roll: %d | Marks: %g\n", s.name, s.roll, s.marks);
    int failed = ferror(file);
    if (fclose(file) != 0 || failed || fields != EOF)
        return 1;
    return 0;
}
