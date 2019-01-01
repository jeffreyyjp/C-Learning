// Write a program that declares a 3x5 array of int and initializes it to some values of your choice. Having the program print the values, double all the values, and then display the new values. Write a function to do the displaying and a second function to do the doubling. Having the functions thake the array name and the number of rows as arguments.
#include<stdio.h>
#define ROWS 3
#define COLS 5
void display_arr(int (*arr)[COLS], int rows);
void double_arr(int (*arr)[COLS], int rows);
int main(void)
{
    int arr[ROWS][COLS] = 
    {
        {4, 4, 4, 3, 2},
        {8, 8, 1, 1, 2},
        {9, 8, 6, 4, 2},
    };
    printf("Original arry is:\n");
    display_arr(arr, ROWS);
    
    double_arr(arr, ROWS);
    printf("After double it, final array is:\n");
    display_arr(arr, ROWS);

    return 0;
}

void display_arr(int (*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void double_arr(int (*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] *= 2;
        }
    }
}