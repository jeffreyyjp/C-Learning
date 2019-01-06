// Modify and test the function in exercise 1 so that it stops after n characters or after the first blank, tab, or newline, whichever comes first.(Don't just use scanf().)
#include<stdio.h>
#include<ctype.h>
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
