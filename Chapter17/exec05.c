// Write a program that lets you input a string. The program then should push the characters of the string onto a stack, one by one (see review question 5), and then pop the character from the stack and display them. This results in displaying the string in reverse oreder.
#include<stdio.h>
#include<string.h>
#include "stack.h"
char * s_gets(char * st, int n);

#define SIZE 45    /* size to hold string */

int main(void)
{
    Stack line;
    Item temp;
    char str[SIZE];
    InitializeStack(&line);
    puts("Please enter a string: ");
    while (s_gets(str, SIZE) != NULL && str[0] != '\0')
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (StackIsFull(&line))
                break;
            temp.ch = str[i];
            Push(temp, &line);
        }
        puts("Reversed order of input string is:");
        while (true)
        {
            if (Pop(&temp, &line))
                printf("%c", temp.ch);
            else
                break;
        }
        puts("\nPlease enter a string: ");
    }
    puts("Bye!");

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