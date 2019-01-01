// Write a function that returns the difference between the largest and smallest elements of an array-of-double. Test the function in a simple program
#include<stdio.h>
#define LENGTH 5
double diff_of_l_and_s(double *ar, int n);
int main(void)
{
    double test_arr[LENGTH] = {3.2, 4.1, 6.2, 2.8, 1.5};
    printf("difference between the largest and smallest elements of ");
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", test_arr[i]);
    printf("is %.1lf.\n", diff_of_l_and_s(test_arr, 5));

    return 0;
}

double diff_of_l_and_s(double *ar, int n)
{
    double largest = *ar;
    double smallest = *ar;
    for (int i = 1; i < n; i++)
    {
        if (*(ar + i) > largest)
            largest = *(ar + i);
        if (*(ar + i) < smallest)
            smallest = *(ar + i);
    }

    return largest - smallest;
}