// Write a function that replaces the contents of a string with the string reversed. Test the function in a complete program that uses a loop to provide input values for feeding to the function.
#include<stdio.h>
#include<string.h>
#define SIZE 10
char * reverse(char *);
char * s_gets(char * st, int n);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    printf("Enter string to reverse.\n");
    while (*s_gets(str, SIZE))
    {
        printf("Reversed string is %s\n", reverse(str));
        printf("Enter string to reverse.\n");
    }
    return 0;
}

char * reverse(char * str)
{
    char temp;
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }

    return str;
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
