/*
Q140: Define a struct with enum Gender and print person's gender.
*/

#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    enum Gender gender;
};

int main(void) {
    const char *names[] = {"Male", "Female", "Other"};
    struct Person person;
    char value[16];

    if (scanf(" Gender = %15s", value) != 1)
        return 1;

    if (strcmp(value, "MALE") == 0)
        person.gender = MALE;
    else if (strcmp(value, "FEMALE") == 0)
        person.gender = FEMALE;
    else if (strcmp(value, "OTHER") == 0)
        person.gender = OTHER;
    else
        return 1;

    puts(names[person.gender]);
    return 0;
}
