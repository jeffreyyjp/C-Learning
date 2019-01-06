// nogo.c -- will this work?
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ANSWER "GRANT"
#define SIZE 40
char * s_gets(char *st, int n);
void to_upper(char * str);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    to_upper(try);
    while (strcmp(try, ANSWER))
    {
        puts("No, that's wrong, Try again.");
        s_gets(try, SIZE);
        to_upper(try);
    }
    puts("That's right!");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void to_upper(char * str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}