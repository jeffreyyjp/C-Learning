/* Write a program that evaluates running totals of these two series up to some limit of number of terms. -1 times itself an odd number of times is -1, and -1 times itself an even number of times is 1. Have the user enter the limit interactively; */
#include<stdio.h>
int main(void)
{
    int terms, i;
    float sum1, sum2, k;
    printf("Enter a terms for infinite series: ");
    while (scanf("%d", &terms) == 1 && terms > 0)
    {
        for (i = 1, k = 1.0, sum1 = 0, sum2 = 0; i <= terms; i++)
        {
            sum1 += 1.0 / i;
            sum2 += k * 1.0 / i;
            k = -k;
        }
        printf("1.0 + 1.0 / 2.0 + 1.0 / 3.0 + 1.0 / 4.0 + ... is %.5f\n", sum1);
        printf("1.0 - 1.0 / 2.0 + 1.0 / 3.0 - 1.0 / 4.0 + ... is %.5f\n", sum2);
        printf("Enter a terms for infinite series(zero or negative to quit): ");
    }

    return 0;
}