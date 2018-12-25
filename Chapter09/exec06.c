// Write and test a function that takes the addresses of thress double variables as arguments and that moves the value of the smallest variable into the first variable, the middle value to the second variable, and the largest value into the thrid variable.
#include<stdio.h>
void transfer_number(double * x, double * y, double * z);

int main(void)
{
    double x, y, z;
    printf("Please enter three double numbers: ");
    while (scanf("%lf %lf %lf", &x, &y, &z) != 3)
    {
        while (getchar() != '\n')
            continue;
        printf("Please enter three double numbers: ");
    }
    printf("Original number: x = %.2lf, y = %.2lf, z = %.2lf\n", x, y, z);
    transfer_number(&x, &y, &z);
    printf("After exchange, x = %.2lf, y = %.2lf, z = %.2lf\n", x, y, z);
    return 0;
}

void transfer_number(double * x, double * y, double * z)
{
    double temp = *x;
    if (*x > *y)
    {
        *x = *y;
        *y = temp;
    }
    temp = *x;
    if (*x > *z)
    {
        *x = *z;
        *z = temp;
    }
    temp = *y;
    if (*y > *z)
    {
        *y = *z;
        *z= temp;
    }
}