/* display_double.c -- display double value using three different ways. */
#include<stdio.h>
#include<float.h>
int main(void)
{
    double d1 = 1.0 / 3.0;
    float f1 = 1.0 / 3.0;
    printf("Original value of d1 and f1 is %f %f.\n", d1, f1);
    printf("%0.4f %0.4f\n", d1, f1);
    printf("%0.12f %0.12f\n", d1, f1);
    printf("%0.16f %0.16f\n", d1, f1);
    printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_DIG: %d\n", DBL_DIG);
}