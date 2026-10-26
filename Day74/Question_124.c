/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
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
static int copy_stream(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF)
        if (fputc(ch, destination) == EOF)
            return 0;
    return !ferror(source);
}
int main(void) {
    char *source_name = read_line(), *destination_name = read_line();
    FILE *source = fopen(source_name, "rb");
    free(source_name);
    if (!source) {
        free(destination_name);
        return 1;
    }
    // Finish reading before opening the destination, which might name the same file.
    FILE *buffer = tmpfile();
    if (!buffer) {
        fclose(source);
        free(destination_name);
        return 1;
    }
    int ok = copy_stream(source, buffer);
    if (fclose(source) != 0)
        ok = 0;
    if (!ok || fseek(buffer, 0, SEEK_SET) != 0) {
        fclose(buffer);
        free(destination_name);
        return 1;
    }
    FILE *destination = fopen(destination_name, "wb");
    if (!destination) {
        fclose(buffer);
        free(destination_name);
        return 1;
    }
    ok = copy_stream(buffer, destination);
    if (fclose(destination) != 0)
        ok = 0;
    fclose(buffer);
    if (ok)
        printf("File copied successfully to %s\n", destination_name);
    free(destination_name);
    return ok ? 0 : 1;
    return 0;
}
