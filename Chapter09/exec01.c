// Devise a function called min(x, y) that returns the smaller of two double values. Test the function with a simple driver
#include<stdio.h>
double min(double, double);
int main(void)
{
    double x, y;
    double min_num;
    printf("Please enter 2 double numbers:\n");
    while (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Please enter 2 double numbers:\n");
        while (getchar() != '\n')
            continue;
    }
    min_num = min(x, y);

    printf("min %.2lf and %.2lf is %.2lf\n", x, y, min_num);
    return 0;
}

double min(double x, double y)
{
    return (x < y) ? x : y;
}