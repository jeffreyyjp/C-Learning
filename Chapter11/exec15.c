// Use the character classification functions to prepare an implementation of atoi(); have this version return the value of 0 if the input string is not a pure number.
#include<stdio.h>
#include<ctype.h>
#define SIZE 10
int check_pure_num(char *);
char * s_gets(char *, int);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    printf("Enter some string to check if is pure number.\n");
    while (*s_gets(str, SIZE) != '\0')
    {
        if (check_pure_num(str))
            printf("%s is pure number.\n", str);
        else
            printf("%s is not pure number.\n", str);
    }
    return 0;
}

int check_pure_num(char * str)
{
    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

char * s_gets(char * str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);

    if (ret_val)
    {
        while (*str != '\n' && *str != '\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}

