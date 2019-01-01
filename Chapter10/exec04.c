// Write a function that returns the index of the largest value stored in an array-of-double. Test the function in a simple program.
#include<stdio.h>
#define LENGTH 5
int get_largest_index(double *ar, int n);
int main(void)
{
    double test_arr[LENGTH] = {3.2, 4.1, 6.2, 2.8, 1.5};
    printf("Index of largest number between ");
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", test_arr[i]);
    printf("is %d.\n", get_largest_index(test_arr, 5));

    return 0;
}

int get_largest_index(double *ar, int n)
{
    int index = 0;
    double largest = *ar;
    for (int i = 1; i < n; i++)
    {
        if (*(ar + i) > largest)
        {
            largest = *(ar + i);
            index = i;
        }
            
    }

    return index;
}