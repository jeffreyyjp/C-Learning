// Write a function called is_within() that takes a character and a string pointer as its two function parameters. Have the function return a nonzero value(true) if the character is in the string and zero(false) otherwise. Test the function in a complete program that uses a loop to proivde input values for feeding to the function.
#include<stdio.h>
#define SIZE 20
int is_within(char *, char);
char * s_gets(char *, int);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    char ch = 'x';
    int result;
    printf("Enter the string for search character %c.\n", ch);
    while (*s_gets(str, SIZE) != '\0')
    {
        result = is_within(str, ch);
        if (result)
            printf("Ok, we found the character %c. in %s\n", ch, str);
        else
            printf("Sorry, We didn't found %c.\n", ch);
    }

    return 0;
}

int is_within(char *str, char ch)
{
    int result = 0;
    
    while (*str != '\0' && *str != ch)
        str++;
    if (*str == ch)
        result = 1;

    return result;
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
