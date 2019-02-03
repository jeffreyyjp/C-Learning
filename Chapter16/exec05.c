// Write a function that takes as arguments the name of an array of type int elements, the size of an array, and a value representing the number of picks. The function then should select the indicated number of items at random from the array and prints them. No array element is to be picked more than once. (This simulates picking lottery numbers or jury members.) Also, if your implementation has time() (discussed in Chapter 12) or a similiar function available, use its output with srand() to initialize the rand() random-number generator. Write a simple program that tests the function.
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100

void random_select(int ar[], int, int);

int main(void)
{
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
        array[i] = i;
    
    int n;
    printf("How many items would you like to pick: ");
    while (scanf("%d", &n) == 1 && n > 0)
    {
        random_select(array, SIZE, n);
        printf("How many items would you like to pick: ");
    }
}

void random_select(int ar[], int size, int picks)
{
    if (picks > size)
    {
        printf("Input error: picks number can't be larger than array size.\n");
        return;
    }
    bool chosen[size];
    for (int i = 0; i < size; i++)
        chosen[i] = false;
    
    srand(time(NULL));
    for (int i = 0; i < picks; i++)
    {
        int index = rand() % size;
        while (chosen[index])
            index = rand() % size;
        printf("%d\n", ar[index]);
        chosen[index] = true;
    }
}