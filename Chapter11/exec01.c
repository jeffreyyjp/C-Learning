// Design and test a function that fetches the next n characters from input (including blanks, tabs, and newlines), storing the results in an array whose address is passed as an argument.
#include<stdio.h>
int main(int argc, char const *argv[])
{
    
    return 0;
}

char * get_n_chars(char *str, int n)
{
    char * ret_val;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (*str != '\0')
            str++;
        if (*str == '\0')
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}