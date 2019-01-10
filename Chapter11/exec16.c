/* Write a program that reads input until end-of-file and echoes it to the display. Have the program recognize and implement the following command-line-argument:
-p      Print input as is
-u      Map input to all uppercase
-l      Map input to all lowercase

Also, if there are no command-line arguments, let the program behave as if the -p argument had been used. */
#include<stdio.h>
#include<ctype.h>
void normal_map(void);
void upper_map(void);
void lower_map(void);

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        normal_map();
        return 0;
    }
    else if (argc > 2 || (argc == 2 && argv[1][0] != '-'))
    {
        printf("Program Usage: program -p|-u|-l\n");
        return 1;
    }
    else
    {
        switch(argv[1][1])
        {
            case 'p':
                normal_map();
                break;
            case 'u':
                upper_map();
                break;
            case 'l':
                lower_map();
                break;
            default:
                printf("Program Usage: program -p|-u|-l\n");
                return 1;
        }
    }
    

    return 0;
}

void normal_map(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);
}

void upper_map(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
        {
            toupper(ch);
            putchar(ch);
        }
    }
}

void lower_map(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
        {
            tolower(ch);
            putchar(ch);
        }
    }
}