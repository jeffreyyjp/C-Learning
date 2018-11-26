/* ASCII_trans.c -- enter an ASCII code value, such as 66, and then prints the character having that ASCII code. */
#include<stdio.h>
int main(void)
{
    int ascii_code;
    printf("Input any integer code for ASCII: ");
    scanf("%d", &ascii_code);
    printf("Convert to character ascii code is %c\n", ascii_code);
    return 0;
}