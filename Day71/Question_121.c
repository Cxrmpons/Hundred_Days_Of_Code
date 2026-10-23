/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *read_line(void) {
    size_t length = 0, capacity = 64;
    char *text = malloc(capacity);
    if (!text)
        exit(1);
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length == capacity - 1) {
            if (capacity > SIZE_MAX / 2)
                exit(1);
            capacity *= 2;
            char *larger = realloc(text, capacity);
            if (!larger) {
                free(text);
                exit(1);
            }
            text = larger;
        }
        text[length++] = (char)ch;
    }
    if (ferror(stdin) || (ch == EOF && length == 0)) {
        free(text);
        exit(1);
    }
    if (length && text[length - 1] == '\r')
        length--;
    text[length] = '\0';
    return text;
}
int main(void) {
    char *line = read_line(), *name = line;
    int age;
    if (strncmp(line, "Name: ", 6) == 0) {
        name = line + 6;
        char *field = strstr(name, ", Age: ");
        char extra;
        if (!field || sscanf(field + 7, "%d %c", &age, &extra) != 1) {
            free(line);
            return 1;
        }
        *field = '\0';
    } else if (scanf("%d", &age) != 1) {
        free(line);
        return 1;
    }
    if (!*name || age < 0) {
        free(line);
        return 1;
    }
    FILE *out = fopen("info.txt", "w");
    if (!out) {
        free(line);
        return 1;
    }
    int written = fprintf(out, "Name: %s\nAge: %d\n", name, age);
    free(line);
    if (fclose(out) != 0 || written < 0)
        return 1;
    puts("File created successfully! Data written to info.txt");
    return 0;
}
