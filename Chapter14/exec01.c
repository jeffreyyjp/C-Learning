// Redo Review Question 5, but make the argument the spelled-out name of the month instead of the month number.(Don't forget about strcmp().)Test the function in a simple program.
#include<stdio.h>
#include<string.h>
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
int days(const struct month[MONTHS], char *);

int main(int argc, char const *argv[])
{
    char name[SLEN];
    int total;
    
    puts("Please enter month name:");
    while (s_gets(name, SLEN) && name[0] != '\0')
    {
        total = days(months, name);
        if (total == -1)
            printf("Invalid month name.\n");
        else
            printf("days in the year up to %s = %d\n", name, total);
        puts("Please enter month name:");
    } 

    return 0;
}

int days(const struct month months[MONTHS], char * name)
{
    int i;
    int index = 1;
    int total;
    for (i = 0; i < MONTHS; i++)
    {
        if (strcmp(months[i].name, name) == 0)
            break;
        else
            index++;
    }
    if (index > MONTHS)
        return (-1);

    for (i = 0, total = 0; i < index; i++)
        total += months[i].days;
    return total;
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
