/*
Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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
    char *path = read_line();
    FILE *file = fopen(path, "r");
    free(path);
    if (!file) {
        puts("Error: File does not exist!");
        return 1;
    }
    puts("File opened successfully.");
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), file))
        if (fputs(buffer, stdout) == EOF) {
            fclose(file);
            return 1;
        }
    int failed = ferror(file);
    if (fclose(file) != 0 || failed)
        return 1;
    return 0;
}
