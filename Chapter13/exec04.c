// Write a program that sequentially displays onscreen all the files listed in the command line. Use argc to control a loop.
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fp;
    int i;
    int ch;
    if (argc == 1)
    {
        printf("Usage: %s filename[filename].\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

    return 0;
}
