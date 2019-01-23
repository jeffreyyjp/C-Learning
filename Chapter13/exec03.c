// Write a file copy program that prompts the user to enter the name of a text file to act as the source file and the name of an output file. The program should use the toupper() function from ctype.h to convert all text to uppercase as it's written to the output file. Use standard I/O and the text mode.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SLEN 81
#define BUFSIZE 409

void copy(FILE *, FILE *);
char * s_gets(char *, int);

int main(int argc, char const *argv[])
{
    FILE * fs, * fd;
    char file_src[SLEN], file_dest[SLEN];

    puts("Please enter name of source file: ");
    s_gets(file_src, SLEN);
    if ((fs = fopen(file_src, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file_src);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create input buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    puts("Please enter name of destination file: ");
    s_gets(file_dest, SLEN);
    if ((fd = fopen(file_dest, "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", file_dest);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fd, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }
    copy(fs, fd);
    printf("Done copying.\n");
    fclose(fs);
    fclose(fd);
    return 0;
}

void copy(FILE * src, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZ];
    while ((bytes = fread(temp, sizeof(char), BUFSIZ, src)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
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
