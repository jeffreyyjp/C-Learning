// Write a function that takes three arguments: a character and two integers. The character is to be printed. The first integer specifies the number of times that the characters is to be printed on a line, and the second integer specifies the number of lines that are to be printed. Write a program that make use of this function.
#include<stdio.h>
void print_char(char, int, int);

int main(void)
{
    char ch;
    unsigned int rows, columns;
    printf("Please enter a character and two integers: ");
    while (scanf("%c %u %u", &ch, &rows, &columns) == 3)
    {
        print_char(ch, rows, columns);
        while (getchar() != '\n')
            continue;
        printf("Please enter a character and two integers: ");
    }
    
    return 0;
}

void print_char(char ch, int rows, int columns)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            putchar(ch);
        }
        printf("\n");
    }
}