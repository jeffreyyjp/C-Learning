// Write a program that generates a list of 100 random numbers in the range 1 - 10 in sorted decreasing order. (You can adapt the sorting algorithm from Chapter11, "Character String and String Functions," to type int. In this case, just sort the numbers themselves.)
#include<stdio.h>
#define SIZE 100
int rand(void);
void sort(int *, int);
static int next = 1;

int main(int argc, char const *argv[])
{
    int i;
    int nums[SIZE];
    for (i = 0; i < SIZE; i++)
        nums[i] = rand();
    
    printf("Original order of nums.\n");
    for (i = 0; i < SIZE; i++)
        printf("%d\n", nums[i]);
    
    sort(nums, SIZE);
    printf("Decreasing order of nums.\n");
    for (i = 0; i < SIZE; i++)
        printf("%d\n", nums[i]);
    return 0;
}

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 10 + 1;
}

void sort(int * arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
