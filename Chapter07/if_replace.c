// if_replace.c -- Using if else statements, write a program that reads input up to #, replaces each period with an exclamation mark, replaces each exclamation mark initially present with two exclamation marks, and reports at the end the number of substitutions it has made
#include<stdio.h>
int main(void)
{
    char ch;
    int repalce_count = 0;
    printf("Enter characters(# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == '!')
        {
            printf("!!");
            repalce_count++;
        }
        else if (ch == '.')
        {
            printf("!");
            repalce_count++;
        }
        else
            printf("%c", ch);
    }
    printf("\ntotal replace count is %d\n", repalce_count);

    return 0;
}