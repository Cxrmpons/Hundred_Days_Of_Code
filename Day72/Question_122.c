/*
Q122: Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
*/

#include <stdio.h>

int main(void) {
    FILE *in = fopen("info.txt", "r");
    if (!in)
        return 1;
    char line[512];
    while (fgets(line, sizeof(line), in))
        if (fputs(line, stdout) == EOF) {
            fclose(in);
            return 1;
        }
    int failed = ferror(in);
    if (fclose(in) != 0 || failed)
        return 1;
    return 0;
}
