// Programs using command-line arguments rely on the user's memory of how to use them correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line arguments, it prompts the user for the required information.
#include<stdio.h>
#include<stdlib.h>  // for exit()
#include<string.h>
#define LEN 10

char * s_gets(char *, int n);

int main(int argc, char const *argv[])
{
    FILE *in, *out;    // declare two FILE pointers
    int ch;
    char file_src[LEN];
    char name[LEN];    // sotrage for output filename;
    int count = 0;

    // set up input
    puts("Please enter name of source file: ");
    s_gets(file_src, LEN);
    if ((in = fopen(file_src, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", file_src);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(name, file_src, LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name, ".red");            // append .red
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);    // print every 3rd char
    }
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

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
