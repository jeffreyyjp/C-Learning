// Modify the program in Listing 13.5 so that it uses a command-line interface instead of an interactive interface.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);

int main(int argc, char const *argv[])
{
    FILE *fa, *fs;        // fa for append file, fs for source files
    int files = 0;        // number of files appends
    int i;
    int ch;
    
    if (argc == 1)
    {
        printf("Usage: %s filename filename...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of destination file:");
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    for (i = 2; i < argc; i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", argv[1]);
            fclose(fs);
            files++;
            printf("File %s appended.\n", argv[i]);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *soruce, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];    // allocate once

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, soruce)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}