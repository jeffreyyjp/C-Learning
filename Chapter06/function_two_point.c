/* function_two_point.c -- Modify exercise 8 so that it uses a function to return the value of the calculation. */
#include<stdio.h>
float calculate(float f1, float f2);
int main(void)
{
    float f1, f2;
    printf("Enter two floating-point numbers: ");
    while (scanf("%f%f", &f1, &f2) == 2)
    {
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", f1, f2, f1, f2, calculate(f1, f2));
        printf("Enter two floating-point numbers(nonnumeric input to quit): ");
    }

    return 0;
}

float calculate(float f1, float f2)
{
    return (f1 - f2) / (f1 * f2);
}