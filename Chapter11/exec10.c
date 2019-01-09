// Write a function that takes a string as an argument and removes the spaces from the string. Test in a program that uses a loop to read lines until you enter an empty line. The program should apply the function to each input string and display the result.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 10
void remove_spaces(char *);
char * s_gets(char *, int);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    printf("Enter string and it's spaces will be removed in the output.\n");
    while (*s_gets(str, SIZE))
    {
        remove_spaces(str);
        printf("Space-removed string is %s\n", str);
        printf("Enter string to continue.\n");
    }
    return 0;
}

void remove_spaces(char * string)
{
    int space_num = 0;
    while (1)
    {
        if (*string == ' ')
            space_num++;
        else
            *(string - space_num) = *string;
        
        if (*string == '\0')
            break;
        string++;
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}