// Write a program that takes as command-line arguments a character and zero or more filenames. If no arguments follow the character, have the program read the standard input. Otherwise, have it open each file in turn and report how many time the character appears in each file. The filename and the character itself should be reported along with the count. Include error-checking to see whether the number of arguments is correct and whether the files can be opened. If a file can't be opened, have the program report that fact and go on to the next file.
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE * fp;
    int search_char, ch;
    int i;
    int count;
    if (argc == 1)
    {
        printf("Usage: %s char[filename...].\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        printf("%c\n", argv[1][0]);
        exit(EXIT_SUCCESS);
    }

    search_char = argv[1][0];
    
    for (i = 2; i < argc; i++)
    {
        count = 0;
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s.\n", argv[i]);
            continue;
        }
        while ((ch = getc(fp)) != EOF)
        {
            if (ch == search_char)
                count++;
        }

        printf("%c has occured %d times in %s\n",search_char,  count, argv[i]);
    }

    fclose(fp);

    return 0;
}
