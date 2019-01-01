// Write a function that sets each element in an array to the sum of the corresponding elements in two others arrays. That is, if array 1 has the values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4 and 6, the function assigns array 3 the values 3, 4, 9, and 14. The function should take three array names and an array size as arguments. Test the function in a simple program.
#include<stdio.h>
#define SIZE 4
void sum_two_arr(int *arr1, int *arr2, int *target, int size);
void display_arr(int *arr, int size);
int main(void)
{
    int arr1[SIZE] = {2, 4, 5, 8};
    int arr2[SIZE] = {1, 0, 4, 6};
    int target[SIZE];
    printf("arr1 is:\n");
    display_arr(arr1, SIZE);
    printf("arr2 is:\n");
    display_arr(arr2, SIZE);

    sum_two_arr(arr1, arr2, target, SIZE);
    printf("Sum of two array, and target is:\n");
    display_arr(target, SIZE);
    
    return 0;
}

void sum_two_arr(int *arr1, int *arr2, int *target, int size)
{
    for (int i = 0; i < size; i++)
    {
        target[i] = arr1[i] + arr2[i];
    }
}

void display_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}