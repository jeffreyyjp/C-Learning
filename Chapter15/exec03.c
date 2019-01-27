// Write a function that takes an int argument and returns the number of "on" bits in the argument. Test the function in a program.
#include<stdio.h>
#include<limits.h>

int num_on(int);

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter a integer number: ");
    while (scanf("%d", &num) == 1 && num >= 0)
    {
        printf("%d has %d \"on\" bits.\n", num, num_on(num));
        printf("Enter a integer number: ");
    }

    return 0;
}

int num_on(int n)
{
    int num = 0;
    while (n != 0)
    {
        if (n & 01)
            num++;
        n >>= 1;
    }

    return num;
}
