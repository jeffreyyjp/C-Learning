// Design and test a function that reads the first word from a line of input into an array and discards the result of the line. It should skip over leading whitespace. Define a word as a sequence of characters with no blanks, tabs, or newlines in it. Use getchar(), not
#include<stdio.h>
#include<ctype.h>
# define SIZE 20
char * get_word(char *);
int main(int argc, char const *argv[])
{
    char str[SIZE];
    char * word;
    printf("Enter some character to get first word.\n");

    word = get_word(str);
    printf("The word is %s\n", word);
    return 0;
}

char * get_word(char * str)
{
    char * ret_val;

    ret_val = gets(str);
    if (ret_val)
    {
        while (*str != '\0' && isspace(*str))
            str++;
        if (!isspace(*str))
            ret_val = str;
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