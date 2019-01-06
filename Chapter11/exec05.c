// Design and test a function that searches the string specified by the first function parameter for the first occurrence or a character specified by the second function parameter. Have the function return a pointer to the character if successful, and a null if the character is not found in the string. (This duplicates the way that the library strchr() function works.) Test the function in a complete program that uses a loop to provide input values for feeding to the functions.
#include<stdio.h>
#define SIZE 20
char * search_ch(char * str, char ch);
char * s_gets(char * st, int n);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    char ch = 'h';
    char * target_ch;
    printf("Enter the string for search character %c.\n", ch);
    while (*s_gets(str, SIZE) != '\0')
    {
        target_ch = search_ch(str, ch);
        if (target_ch)
            printf("%s.\n", target_ch);
    }

    return 0;
}

char * search_ch(char * str, char ch)
{

    while (*str != '\0' && *str != ch)
        str++;
    if (*str == '\0')
        return NULL;
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

