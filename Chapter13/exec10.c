// Write a program that opens a text file whose name is obtained interactively. Set up a loop that asks the user to enter a file position. The program then should print the part of the file starting at that position and proceed to the next newline character. Let negative or nonnumeric input terminate the user-input loop.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 10

char * s_gets(char *, int);

int main(int argc, char const *argv[])
{
    FILE * fp;
    char file_src[SLEN];
    long pos;
    int ch;
    puts("Enter a file name to play:");
    s_gets(file_src, SLEN);
    if ((fp = fopen(file_src, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file_src);
        exit(EXIT_FAILURE);
    }
    
    puts("Enter a number to move to that position:");
    while (scanf("%ld", &pos) == 1 && pos > 0)
    {
        while (getchar() != '\n')
            continue;
        if (fseek(fp, pos, SEEK_SET) != 0)
        {
            fprintf(stderr, "Can't set file position of %ld.\n", pos);
            continue;
        }
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        putchar('\n');

        puts("Enter a number to move to that position:");
    }

    fclose(fp);
           
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
