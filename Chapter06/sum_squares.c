/* sum_squares.c -- Write a program that requests lower and upper integer limits, calculates the sum of all the integer squares from the square of the lower limit to the square of the upper limit, and displays the answer. */
#include<stdio.h>
int main(void)
{
    int lower, upper, sum = 0;
    printf("Enter lower and uppser integer limits: ");
    while (scanf("%d%d", &lower, &upper) == 2 && upper > lower)
    {
        for (int i = lower; i <= upper; i++)
            sum += i * i;
        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    return 0;
}