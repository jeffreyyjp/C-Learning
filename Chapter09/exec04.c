// The harmonic mean of two numbers is obtained by taking the inverses of the two numbers, averaging them, and taking the inverse of the result. Write a function that takes two double arguments and returns the harmonic mean of the two numbers.
#include<stdio.h>
double harmonic(double, double);

int main(void)
{
    double x, y;
    printf("Harmonic mean\n");
    printf("Enter two double numbers: ");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        while (getchar() != '\n')
            continue;
        printf("Enter two double numbers: ");
    }
    printf("harmonic mean of %.2lf and %.2lf is %.2lf\n", x, y, harmonic(x, y));
    return 0;
}

double harmonic(double x, double y)
{
    return 2.0 / (1.0 / x + 1.0 / y);
}