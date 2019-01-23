/* Write a program that opens two files. You can obtain the filenames either by using command-line arguments or by soliciting the user to enter them.
   a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the first file, line2 of the second file, and so on, until the last line of the longer file (in terms of lines) is printed.

   b. Modify the program so that lines with the same line number are printed on the same line. */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SLEN 10

char * s_gets(char *, int);

int main(int argc, char const *argv[])
{
    FILE * fp1, * fp2;
    char file1[SLEN], file2[SLEN];
    int ch1, ch2;

    puts("Please enter first file name: ");
    s_gets(file1, SLEN);
    if ((fp1 = fopen(file1, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file1);
        exit(EXIT_FAILURE);
    }

    puts("Please enter second file name: ");
    s_gets(file2, SLEN);
    if ((fp2 = fopen(file2, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file2);
        exit(EXIT_FAILURE);
    }

    puts("Output content is:");
    while (1)
    {
        while ((ch1 = getc(fp1)) != EOF)
        {
            if (ch1 != '\n')
                putchar(ch1);
            else
            {
                putchar('\n');
                break;
            }
        }

        while ((ch2 = getc(fp2)) != EOF)
        {
            if (ch2 != '\n')
                putchar(ch2);
            else
            {
                putchar('\n');
                break;
            }
        }

        if (ch1 == EOF && ch2 == EOF)
            break;
        
    }
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}