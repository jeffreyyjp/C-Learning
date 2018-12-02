/* dollar_letter.c -- Use nested loops to produce the following pattern:
$
$$
$$$
$$$$
$$$$$
*/
#include<stdio.h>
int main(void)
{
    const char LETTER = '$';
    const int LINE_NUM = 5;
    int i, j;
    for (i = 0; i < LINE_NUM; i++)
    {
        for (j = 0; j < i + 1; j++)
            printf("%c", LETTER);
        printf("\n");
    }
    
    return 0;
}