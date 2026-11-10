/*
Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
*/

#include <stdio.h>
#include <string.h>

enum Role { ADMIN, USER, GUEST };

int main(void) {
    char input[16];
    enum Role role;
    if (scanf("%15s", input) != 1)
        return 1;

    if (strcmp(input, "ADMIN") == 0)
        role = ADMIN;
    else if (strcmp(input, "USER") == 0)
        role = USER;
    else if (strcmp(input, "GUEST") == 0)
        role = GUEST;
    else
        return 1;

    const char *names[] = { [ADMIN] = "Admin", [USER] = "User", [GUEST] = "Guest" };
    printf("Welcome %s!\n", names[role]);
    return 0;
}
