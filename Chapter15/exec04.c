// Write a function that takes two int arguments: a value and a bit position. Have the function return 1 if that particular bit position is 1, and have it return 0 otherwise. Test the function in a program.
#include<stdio.h>

int check_position(int, int);

int main(int argc, char const *argv[])
{
    int value;
    int pos;
    printf("Enter an integer: ");
    while (scanf("%d", &value) == 1)
    {
        printf("Enter a position: ");
        while (scanf("%d", &pos) == 1)
        {
            printf("%d in position %d is %d.\n", value, pos, check_position(value, pos));
            printf("Enter a position: ");
        }
        while (getchar() != '\n')
            continue;
        printf("Enter an integer: ");
    }

    return 0;
}

int check_position(int n, int pos)
{
    return (n >>= pos) & 1;
}

