// count_character.c -- Write a program that reads input until encountering the # character and then reports the number of spaces read, the number of newline characters read, and the number of all other characters read. */
#include<stdio.h>
#include<ctype.h>
# define QUIT_TAG '#'
int main(void)
{
    char ch;
    int n_spaces = 0;
    int n_lines = 0;
    long n_characters = 0L;
    printf("Enter characters to count:\n");
    while ((ch = getchar()) != QUIT_TAG)
    {
        if (ch == '\n')
            n_lines++;
        else if (isspace(ch))
            n_spaces++;
        else
            n_characters++;
    }
    printf("spaces is %d, lines is %d, other characters is %ld\n", n_spaces, n_lines, n_characters);

    return 0;
}