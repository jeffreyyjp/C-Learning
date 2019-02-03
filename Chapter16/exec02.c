// The harmonic mean of two numbers is obtained by taking the inverses of the two numbers, averaging them, and taking the inverse of the result. Use a #define directive to define a macro "function" that performs this operation. Write a simple program that tests the macro.
#include<stdio.h>

#define INVERSE(X) (1.0 / (X))
#define HARMONIC(X, Y) (1.0 / ((INVERSE(X) + INVERSE(Y)) / 2))

int main()
{
    int x, y;
    printf("Please enter 2 integers x and y: ");
    while (scanf("%d %d", &x, &y) != 2)
    {
        while (getchar() != '\n') continue;

        printf("Please enter 2 integers x and y: ");
    }

    printf("hormonic of x and y is %f\n", HARMONIC(x, y));

    return 0;
}