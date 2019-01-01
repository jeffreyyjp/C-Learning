/* Write a program that prompts the user to enter three sets of five double numbers each. (You may assume the user responds correctly and doesn't enter non-numeric data.) The program should accomplish all of the following:
    a. Store the information in a 3x5 array.
    b. Compute the average of each set of five values.
    c. Compute the average of all the values.
    d. Determine the largest value of the 15 values.
    e. Report the results.
Each major task should be handled by a separate funciton using the traditional C apporach to handling arrays. Accomplish task "b" by using a function that computes and returns the average of a one-dimensional array; use a loop to call this function three times. The other tasks should take the entire array as an argument, and the functions performing task "c" and "d" should return the answer to the calling program. */
#include<stdio.h>
#define ROWS 3
#define COLS 5
double average_one_set(double *ar, int cols);
double average_all(double (*ar)[COLS], int rows);
double largest_of_all(double (*ar)[COLS], int rows);
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
    
    printf("Average of all sets is %.2lf.\n", average_all(ar, ROWS));
    printf("Largest elements of arr is %.2lf.\n", largest_of_all(ar, ROWS));

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

double average_all(double (*ar)[COLS], int rows)
{
    double total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            total += ar[i][j];
        }
    }
    return total / (COLS * rows);
}

double largest_of_all(double (*ar)[COLS], int rows)
{
    double largest = **ar;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (largest < ar[i][j])
                largest = ar[i][j];
        }
    }
    return largest;
}