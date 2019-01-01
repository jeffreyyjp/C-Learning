// Write a function that reverses the contents of an array of double and test in a simple program.
#include<stdio.h>
#define LENGTH 5
void reverse_arr(double *ar, int n);
int main(void)
{
    double test_arr[LENGTH] = {3.2, 4.1, 6.2, 2.8, 1.5};
    printf("Reverses the contents of an array of double: ");
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", test_arr[i]);
    
    reverse_arr(test_arr, LENGTH);
    printf("\nAfter reversed, content of array is: ");
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", test_arr[i]);
    
    return 0;
}

void reverse_arr(double *ar, int n)
{
    double k;
    for (int i = 0; i < n / 2; i++)
    {
        k = *(ar + i);
        *(ar + i) = *(ar + n - i - 1);
        *(ar + n - i - 1) = k;
    }
        
}