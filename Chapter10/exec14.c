// Do Programming Exercise 13, but use variable-length array function parameters
#include<stdio.h>
#define ROWS 3
#define COLS 5
double average_one_set(double *ar, int cols);
double average_all(int rows, int cols, double ar[rows][cols]);
double largest_of_all(int rows, int cols, double ar[rows][cols]);
int main(void)
{
    double ar[ROWS][COLS];
    printf("Please enter three set of five double numbers each:\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("Enter set of %d double numbers.\n", i);
        for (int j = 0; j < COLS; j++)
        {
            scanf("%lf", ar[i] + j);
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%.2lf ", ar[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < ROWS; i++)
    {
        printf("Average of set %d is %.2lf.\n", i, average_one_set(ar[i], COLS));
    }
    
    printf("Average of all sets is %.2lf.\n", average_all(ROWS, COLS, ar));
    printf("Largest elements of arr is %.2lf.\n", largest_of_all(ROWS, COLS, ar));

    return 0;
}

double average_one_set(double *ar, int cols)
{
    double total = 0;
    for (int i = 0; i < cols; i++)
    {
        total += ar[i];
    }
    return total / cols;
}

double average_all(int rows, int cols, double ar[rows][cols])
{
    double total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += ar[i][j];
        }
    }
    return total / (rows * cols);
}

double largest_of_all(int rows, int cols, double ar[rows][cols])
{
    double largest = **ar;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (largest < ar[i][j])
                largest = ar[i][j];
        }
    }
    return largest;
}