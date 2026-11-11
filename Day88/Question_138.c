/*
Q138: Print all enum names and integer values using a loop.
*/

#include <stdio.h>

enum Light { RED, YELLOW, GREEN };

int main(void) {
    const char *names[] = { [RED] = "RED", [YELLOW] = "YELLOW", [GREEN] = "GREEN" };
    for (int light = RED; light <= GREEN; light++)
        printf("%s=%d\n", names[light], light);
    return 0;
}
