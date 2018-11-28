/* print-float.c -- reads a floating-point number and prints it first in decimal-point notation and then in exponential notation. */
#include<stdio.h>
int main(void)
{
    float float_num;
    printf("Enter a float num: ");
    scanf("%f", &float_num);
    printf("The input is %.1f or %.1e.\n", float_num, float_num);
    printf("The input is %+.3f or %.3E\n", float_num, float_num);

    return 0;
}