/*
Q132: Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
*/

#include <stdio.h>
#include <string.h>
enum Light { RED, YELLOW, GREEN };
int main(void) {
    char name[16];
    if (scanf("%15s", name) != 1)
        return 1;
    enum Light light;
    if (strcmp(name, "RED") == 0)
        light = RED;
    else if (strcmp(name, "YELLOW") == 0)
        light = YELLOW;
    else if (strcmp(name, "GREEN") == 0)
        light = GREEN;
    else
        return 1;
    switch (light) {
    case RED:
        puts("Stop");
        break;
    case YELLOW:
        puts("Wait");
        break;
    case GREEN:
        puts("Go");
        break;
    }
    return 0;
}
