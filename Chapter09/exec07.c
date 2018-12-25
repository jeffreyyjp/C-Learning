// Write a program that reads characters from the standard input to end-of-file. For each character, have the program report whether it is a letter. If it is a letter, also report its numerical location in the alphabet. For example, c and C would both be letter 3. Incorporate a function that takes a character as an argument and returns the numerical location if the character is a letter and that return -1 otherwise
#include<stdio.h>
int get_location(char ch);

int main(void)
{
    int location;
    char ch;
    printf("Enter characters:\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
            continue;
        location = get_location(ch);
        if (location == -1)
            printf("%c is not a letter\n", ch);
        else
            printf("location of %c is %d\n", ch, location);
    }
    return 0;
}

int get_location(char ch)
{
    int location;
    // if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    //     location = toupper(ch) - 64;
    // else
    //     location = -1;
    if (ch >= 65 && ch <= 90)
        location = ch - 64;
    else if (ch >= 97 && ch <= 122)
        location = ch - 96;
    else
        location = -1;
    return location;   
}