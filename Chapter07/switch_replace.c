// switch_replace.c -- Redo exercise "if_replace.c" using a switch
#include<stdio.h>
int main(void)
{
    char ch;
    int repalce_count = 0;
    printf("Enter characters(# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case '!':
                printf("!!");
                repalce_count++;
                break;
            case '.':
                printf("!");
                repalce_count++;
                break;
            default:
                printf("%c", ch);
        }
    }
    printf("\ntotal replace count is %d\n", repalce_count);

    return 0;
}