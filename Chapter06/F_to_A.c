/* F_to_A.c -- Use nested loops to produce the following patterns:
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
#include<stdio.h>
int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        for (char c = 'F'; 'F' - c < i + 1; c--)
            printf("%c", c);
        printf("\n");
    }

    return 0;
}