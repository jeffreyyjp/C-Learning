// Write a program that initializes a two-dimensional array-of-double and uses one of the copy functions from exercise 2 to copy it to a second two-dimensional array. (Because a two-dimensional array is an array of arrays, a one-dimensional copy function can be used with each subarray.)
#include<stdio.h>
#define ROWS 4
#define COLS 2
void copy_two_dimen_arr(double (*target)[COLS], double (*source)[COLS], int n);
int main(void)
{
    double source_arr[ROWS][COLS] = {{2.2, 4.1}, {6.3, 8.5}, {1.1, 3.8}, {5.4, 7.2}};
    double target_arr[ROWS][COLS];
    printf("Copy to target array from source array\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%.1lf ", source_arr[i][j]);
        printf("\n");
    }
    copy_two_dimen_arr(target_arr, source_arr, ROWS);
    printf("\nAfter copied, the target array is:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%.1lf ", target_arr[i][j]);
        printf("\n");
    }

    return 0;
}

void copy_two_dimen_arr(double (*target)[COLS], double (*source)[COLS], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(target[i] + j) = *(source[i] + j);
        }
    }
}