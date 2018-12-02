/* pyramid_pattern.c -- Have a program request the user to enter an uppercase letter. Use nested loops to produce a pyramid pattern like this:
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
#include<stdio.h>
int main(void)
{
    char c;
    int row;
    printf("Enter a uppercase letter: ");
    scanf("%c", &c);
    row = c - 'A' + 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row - i - 1; j++)
            printf("%c", ' ');
        for (char c = 'A'; c <= 'A' + i; c++)
            printf("%c", c);
        for (char c = 'A' + i - 1; c >= 'A'; c--)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}