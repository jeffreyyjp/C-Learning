// Write and test a function larger_of() that replaces the content of two double variables with the maximum of the two values. For example, larger_of(x, y) would reset both x and y to the larger of the two.
#include<stdio.h>
void larger_of(double * x, double * y);

int main(void)
{
    double x, y;
    printf("Enter two double numbers: ");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        while (getchar() != '\n')
            continue;
        printf("Enter two double numbers: ");
    }
    printf("original x = %.2lf and y = %.2lf\n", x, y);
    larger_of(&x, &y);
    printf("After replace, x = %.2lf and y = %.2lf\n", x, y);

    return 0;
}

void larger_of(double * x, double * y)
{
    if (*x > *y)
        *y = *x;
    else
        *x = *y;
}