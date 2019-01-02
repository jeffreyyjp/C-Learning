// nogo.c -- will this work?
#include<stdio.h>
#include<string.h>

#define ANSWER "Grant"
#define SIZE 40
char * s_gets(char *st, int n);

int main(void)
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER))
    {
        puts("No, that's wrong, Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");

    return 0;
}