/* A_to_U.c -- Use nested loops to produce the following pattern:
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/
#include<stdio.h>
int main(void)
{
    char c = 'A';
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i + 1; j++)
            printf("%c", c++);
        printf("\n");
    }

    return 0;
}