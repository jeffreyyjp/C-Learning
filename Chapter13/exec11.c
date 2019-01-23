// Wirte a program that takes two command-line arguments. The first is a string; the second is the name of a file. The program should then search the file, printing all lines containing the string. Because this task is line oriented rather than character oriented, use fgets() instead of getc(). Use the standard C library function strstr() (briefly described in exercise 7 of Chapter 11) to search each line for the string. Assume no lines are longer than 255 characters.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 60

int main(int argc, char const *argv[])
{
    FILE * fp;
    char str[SLEN];

    if (argc != 3)
    {
        printf("Usage: %s str filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(str, SLEN, fp))
    {
        if (strstr(str, argv[1]))
            printf("%s", str);
    }

    fclose(fp);

    return 0;
}
