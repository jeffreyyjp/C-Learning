/* Write a program that requests two floating-point numbers and prints the value of their difference divided by their product. Having the program loop through pairs of input values until the user enters nonnumeric input. */
#include<stdio.h>
int main(void)
{
    float f1, f2;
    printf("Enter two floating-point numbers: ");
    while (scanf("%f%f", &f1, &f2) == 2)
    {
        printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", f1, f2, f1, f2, (f1 - f2) / (f1 * f2));
        printf("Enter two floating-point numbers(nonnumeric input to quit): ");
    }

    return 0;
}