// Modify the program in Listing 13.3 so that each word is numbered according to the order in which it was added to the list, starting with 1. Make sure that, when the program is run a second time, new word numbering resumes where the previous numbering left off.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main(int argc, char const *argv[])
{
    FILE *fp;
    char words[MAX];
    int count = 0;
    int ch;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    // Get numbers of word
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
            count++;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the begining of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%d.%s\n",++count, words);  /* add line number */
    
    puts("File contents:");
    rewind(fp);        /* go back to begining of file */
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
