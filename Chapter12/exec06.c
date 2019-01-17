// Write a program that generates 1,000 random numbers in the range 1-10. Don't save or print the numbers, but do print how many times each number was produced. Having the program do this for 10 different seed values. Do the numbers appear in equal amounts? You can use the functions from this chapter or the ANSI C rand() and srand() functions, which follow the same format that our functions do. This is one way to examine the randomness of a particular random-number generator.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
#define COUNT 10
void print_each_count(unsigned int *, int);

int main(int argc, char const *argv[])
{
    int i = 0;
    int j;
    int seed;
    unsigned int nums[SIZE];
    printf("Enter number larger than 0 to set seed.\n");
    while (scanf("%d", &seed) == 1 && seed > 0 && i < COUNT)
    {
        srand(seed);
        for (j = 0; j < SIZE; j++)
            nums[j] = rand() % 10 + 1;
        print_each_count(nums, SIZE);

        printf("Enter number larger than 0 to set seed.\n");
        i++;
    }

    return 0;
}

void print_each_count(unsigned int * arr, int n)
{
    int i;
    int each_count[COUNT] = {0};
    for (i = 0; i < n; i++)
    {
        each_count[arr[i] - 1]++;
    }

    for (i = 0; i < COUNT; i++)
        printf("count of %d = %d.\n", i + 1, each_count[i]);
}

