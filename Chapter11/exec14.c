// Write a power-law program that works on a command-line basis. The first command-line argument should be the type double number to be raised to a certain power, and the second argument should be the integer power.
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    double base;
    int power;
    double result = 1;
    if (argc != 3)
        exit(0);
    base = atof(argv[1]);
    power = atoi(argv[2]);
    for (int i = 0; i < power; i++)
    {
        result *= base;
    }

    printf("%lf ** %d = %lf\n", base, power, result);

    return 0;
}
