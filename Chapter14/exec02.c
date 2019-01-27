// Write a program that prompts the user to enter the day, month, and year. The month can be a month number, a month name, or a month abbreviation. The program then should return the total number of days in the year up through the givenn day. (Do take leap years account).
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SLEN 10
#define MONTHS 12

struct month
{
    /* data */
    char name[10];
    char abbr[4];
    int days;
    int num;
};

struct month months[MONTHS] = 
{
    {"Januray", "jan", 31, 1},
    {"February", "feb", 28, 2},
    {"March", "mar", 31, 3},
    {"April", "apr", 30, 4},
    {"May", "may", 31, 5},
    {"June", "jun", 30, 6},
    {"July", "jul", 31, 7},
    {"August", "aug", 31, 8},
    {"September", "sep", 30, 9},
    {"October", "oct", 31, 10},
    {"November", "nov", 30, 11},
    {"December", "dec", 31, 12}
};

char * s_gets(char *, int);

int main(int argc, char const *argv[])
{
    int year, day;
    int total = 0;
    int i;
    char month[SLEN];

    printf("Please enter a year: ");
    while (scanf("%d", &year) != 1)
    {
        while (getchar() != '\n') continue;  // clear input stream.
        printf("Please enter a year: ");
    }
    while (getchar() != '\n') continue;  // clear input stream.
    
    printf("Please enter a month by name, abbreviation, ");
    printf("or a number (eg. January, jan or 1): ");
    s_gets(month, SLEN);

    printf("Please enter a day: ");
    while (scanf("%d", &day) != 1)
    {
        while (getchar() != '\n') continue;  // clear input stream.
        printf("Please enter a day: ");
    }
    while (getchar() != '\n') continue;  // clear input stream.

    for (i = 0; i < MONTHS; i++)
    {
        if (strcmp(month, months[i].name) == 0 || strcmp(month, months[i].abbr) == 0 || atoi(month) == months[i].num)
            break;

    }
    if (i == MONTHS)
    {
        printf("No month matching %s found.\n", month);
        exit(EXIT_FAILURE);
    }
    
    // check if year is leap year.
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        months[1].days = 29;
    
    if (day > months[i].days)
    {
        printf("Invalid date, there is no data %d in %s %d\n", day, months[i].name, year);
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < i; j++)
        total += months[j].days;
    total += day;

    printf("There are %d in %d through %s %d.\n", total, year, months[i].name, day);

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}