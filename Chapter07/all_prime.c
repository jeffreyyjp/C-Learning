// Write a program that accepts a positive integer as input and then displays all the prime numbers smaller than or equal to that number.
#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    int num;
    bool is_prime;
    printf("This program prints all prime numbers smaller than or equal to any positve integer\n");
    printf("Enter a positive integer:\n");
    while (scanf("%d", &num) != 1 || num < 1)
    {
        while (getchar() != '\n')
            ;
        printf("Enter a positive integer:\n");
    }
    for (int i = 2; i <= num; i++)
    {
        is_prime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            printf("%d is prime.\n", i);
    }

    return 0;
}