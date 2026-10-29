/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in)
        return 1;
    FILE *out = fopen("output.txt", "w");
    if (!out) {
        fclose(in);
        return 1;
    }
    int ch, ok = 1;
    while ((ch = fgetc(in)) != EOF)
        if (fputc(toupper(ch), out) == EOF) {
            ok = 0;
            break;
        }
    if (ferror(in))
        ok = 0;
    if (fclose(in) != 0)
        ok = 0;
    if (fclose(out) != 0)
        ok = 0;
    return ok ? 0 : 1;
    return 0;
}
