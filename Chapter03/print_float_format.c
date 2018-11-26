/* print_float_format.c -- print floating-point number using different formats. */
#include<stdio.h>
int main(void)
{
    float float_number;
    printf("Enter a floating-point value: ");
    scanf("%f", &float_number);
    printf("fixed-point notation: %f\n", float_number);
    printf("exponential notation: %e\n", float_number);
    printf("p notation: %a\n", float_number);

    return 0;
}