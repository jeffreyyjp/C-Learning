// Write a program that initializes a two-dimensional 3x5 array-of-double and uses a VLA-based function to copy it to a second two-dimensional array. Also provide a VLA-based function to display the contents of the two arrays. The two functions should be capable, in general, of processing arbitrary NxM arrays. (If you don't have access to a VLA-capable compiler, use the traditional C approach of functions that can process an Nx5 array).
#include<stdio.h>
#define ROWS 3
#define COLS 5
void copy_two_dimen_arr(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void show_two_dimen_arr(int rows, int cols, double arr[rows][cols]);
int main(void)
{
    double source[ROWS][COLS] = 
    {
        {4.3, 4.3, 4.3, 3.0, 2.0},
        {8.5, 8.2, 1.2, 1.6, 2.4},
        {9.1, 8.5, 6.7, 4.3, 2.1},
    };
    double target[ROWS][COLS];
    printf("Source of two-dimensional double array is:\n");
    show_two_dimen_arr(ROWS, COLS, source);
    
    copy_two_dimen_arr(ROWS, COLS, target, source);
    printf("After copy from source to target, target array is:\n");
    show_two_dimen_arr(ROWS, COLS, target);

    return 0;
}

void copy_two_dimen_arr(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void show_two_dimen_arr(int rows, int cols, double arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.2lf ", arr[i][j]);
        }
        printf("\n");
    }
}