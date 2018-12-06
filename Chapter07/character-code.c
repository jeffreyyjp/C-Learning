// character-code.c -- Write a program that reads input until encountering #. Have the program print each input character and its ASCII decimal code. Print eight character-code pairs per line. */
#include<stdio.h>
int main(void)
{
    char ch;
    int count_char = 0;
    printf("Enter characters:\n");
    while ((ch = getchar()) != '#')
    {
        if (count_char % 8 == 0)
            printf("\n");
        count_char++;
        printf("(%c %d) ", ch, ch);
    }
    printf("\n");
    
    return 0;
}