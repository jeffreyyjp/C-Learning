// count_sequence.c -- Write a program that reads input up to # and reports the number of times that the sequence "ei" occurs. */
#include<stdio.h>
int main(void)
{
    char ch, prev = '!';
    int count = 0;
    printf("Enter characters for counting 'e':\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == 'i' && prev == 'e')
            count++;
        prev = ch;
    }
    printf("The total number of times of 'ei' is %d\n", count);

    return 0;
}