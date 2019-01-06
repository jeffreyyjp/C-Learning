// Design and test a function like that described in Porgramming Exercise 3 except that it accepts a second parameter specifying the maximum number of characters that can be read.
#include<stdio.h>
#include<ctype.h>
# define SIZE 20
char * get_word(char *, int);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    char * word;
    printf("Enter some character to get first word.\n");

    word = get_word(str, SIZE);
    printf("The word is %s\n", word);
    return 0;
}

char * get_word(char * str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        // First to find the character is not whitespace
        while (*str != '\0' && isspace(*str))
            str++;
        // The first non-whitespace character is our pointer address
        if (!isspace(*str))
            ret_val = str;
        // Find next whitespace character and replace it with '\0'
        while (*str != '\0' && !isspace(*str))
            str++;
        if (isspace(*str))
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}
