// Write a function that takes three arguments: the name of an array of sorted integers, the number of elements of the array, and an integer to seek. The function returns the value 1 if the integer is in the array, and 0 if it isn't. Having the function use the binary search technique.
#include<stdio.h>
#define SIZE 5

int search_item(int *, int, int);

int main(void)
{
    int arr[SIZE] = {1, 3, 6, 8, 11};
    int seek_num;
    printf("Please enter number to seek: ");
    while (scanf("%d", &seek_num) == 1)
    {
        while (getchar() != '\n')
            continue;
        
        if (search_item(arr, SIZE, seek_num) == 1)
            printf("Found.\n");
        else
            printf("Not found.\n");
        printf("Please enter number to seek: ");
    }
    

    return 0;
}

int search_item(int arr[], int num, int seek_num)
{
    int low = 0;
    int high = num - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (seek_num == arr[mid])
            return 1;
        if (seek_num > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}