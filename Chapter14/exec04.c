/* Write a program that creates a structure template with two members according to the following criteria:
    a. The first member is a social security number. The second member is a structure with three members. Its first member contains a first name, its seconds member contains a middle name, and its final member contains a last name. Create and initialize an array of five such structures. Have the program print the data in this format:
    Dribble, Flossie M. - 302039823

Only the initial letter of the middle name is printed, and a period is added. Neither the initial(of course) nor the period should be printed if the middle name member is empty. Write a function to do the printing; pass the structure array to the function.
    b. Modify part a. by passing the structure value instead of the address. */
#include<stdio.h>
#include<string.h>
#define LEN 5
#define MAXNAME 20

struct names {
    char first[MAXNAME];
    char middle[MAXNAME];
    char last[MAXNAME];
};

struct person {
    char ssn[MAXNAME];
    struct names handle;
};

void printperson_a(struct person *);
void printperson_b(struct person);

int main(void)
{
    struct person fellow[LEN] = {
        {"123456789", {"Marvin", "The", "Martian"}},
		{"987654321", {"Scrooge", "Mc", "Duck"}},
		{"888777666", {"Mantis", "Froggy", "Tobogan"}},
		{"123432467", {.first="Night", .last="Man"}},
		{"354257623", {.first="Day", .last="Man"}}
    };
    // part a -- pass by address
    for (int i = 0; i < LEN; i++)
        printperson_a(&fellow[i]);
    putchar('\n');
    // part b -- pass by structure value
    for (int i = 0; i < LEN; i++)
        printperson_b(fellow[i]);

    return 0;
}

void printperson_a(struct person *fellow)
{
    printf("%s, %s ", fellow->handle.last, fellow->handle.first);
    if (fellow->handle.middle[0] != '\0')
        printf("%c. ", fellow->handle.middle[0]);
    printf("- %s\n", fellow->ssn);
}

void printperson_b(struct person fellow)
{
    printf("%s, %s ", fellow.handle.last, fellow.handle.first);
    if (fellow.handle.middle[0] != '\0')
        printf("%c. ", fellow.handle.middle[0]);
    printf("- %s\n", fellow.ssn);
}

