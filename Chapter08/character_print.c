// character_print.c -- Write a program that reads input as a stream of characters until encountering EOF. Have the program print each input character and its ASCII decimal value. Note theat characters preceding the space character in the ASCII sequence are nonprinting characters. Treating them specially. If the nonprinting character is a newline or tab, print
#include<stdio.h>
int main(void)
{
    int ch;
    int char_count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= ' ')
            printf("\'%c\' : %d", ch, ch);
        else if (ch == '\n')
            printf("\'\\n\'");
        else if (ch == '\t')
            printf("\'\\t\'");
        else
            printf("\'^%c\' : %d", ch + 64, ch);
        
        char_count++;
        if (char_count % 10 == 0)
            printf("\n");
        else
            printf(" ");
    }

    return 0;
}