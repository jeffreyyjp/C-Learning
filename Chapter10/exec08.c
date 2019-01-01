// Use a copy function from Programming Exercise 2 to copy the third through fifth elements of a seven-element array into a three-element array. The function itself need not be altered; just choose the right actual arguments. (The actual arguments need not be an array name and array size. They only have to be the address of an array element and a number of elements to be processed.)
#include<stdio.h>
void copy(int *target, int *startelement, int num_size);
int main(void)
{
    int source[7] = {1, 2, 3, 4, 5, 6, 7};
    int target[3];
    printf("Copy the third through fifth elements of a seven-element array into a three-element array.\n");
    copy(target, source + 2, 3);
    printf("After copied, the target array is:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", target[i]);
    }
    return 0;
}


// from start address of array[i] to copy number of size to target array.
void copy(int *target, int *startelement, int num_size)
{
    for (int *ptr = startelement; ptr < startelement + num_size; target++, ptr++)
    {
        *target = *ptr;
    }
}