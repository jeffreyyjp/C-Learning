// Redo Programming Exercise 8, but this time use a recursive function.
#include<stdio.h>
double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\n the number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        if (x == 0 && exp == 0)
        {
            printf("0 to the 0 is undefined.\n");
            printf("Enter next pair of numbers or q to quit.\n");
            continue;
        }
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}

double power(double n, int p)
{
    double pow = 1;
    int i;
    if (p > 0)
    {
        // for (i = 1; i <= p; i++)
        //     pow *= n;
        pow = n * power(n, p - 1);
    }
    if (p < 0)
    {
        // for (i = 1; i <= (-p); i++)
        //     pow *= 1 / n;
        pow = 1 / n * power(1 / n, -p - 1);
    }
    if (n != 0.0 && p == 0)
        pow = 1;
    if (n == 0.0 && p != 0)
        pow = 0;
    
    return pow;
}