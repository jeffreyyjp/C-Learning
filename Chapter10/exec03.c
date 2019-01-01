// Write a functionn that returns the largest value stored in an array-of-int. Test the function in a simple program.
#include<stdio.h>
#define LENGTH 5
int get_largest(int *ar, int n);
int main(void)
{
    int test_arr[LENGTH] = {3, 4, 1, 2, 2};
    printf("Largest number between ");
    for (int i = 0; i < LENGTH; i++)
        printf("%d ", test_arr[i]);
    printf("is %d.\n", get_largest(test_arr, 5));

    return 0;
}

int get_largest(int *ar, int n)
{
    int largest = *ar;
    for (int i = 1; i < n; i++)
    {
        if (*(ar + i) > largest)
            largest = *(ar + i);
    }

    return largest;
}