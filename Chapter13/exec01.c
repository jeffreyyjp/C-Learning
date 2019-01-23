// Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user's response instead of using command-line argument.
#include<stdio.h>
#include<stdlib.h>    // exit() prototype
#include<string.h>
#define SLEN 81
char * s_gets(char *, int);

int main(void)
{
    int ch;        // place to store each character as read
    FILE *fp;      // "file pointer"
    char file_src[SLEN];
    unsigned long count = 0;

    printf("Please enter file name: ");
    s_gets(file_src, SLEN);
    if ((fp = fopen(file_src, "r")) == NULL)
    {
        printf("Can't open %s\n", file_src);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // same as putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file_src, count);

    
    return 0;
}

char * s_gets(char * st, int n)
{
    char *ret_val;
    char *find;
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
