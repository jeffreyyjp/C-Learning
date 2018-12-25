// Write and test a Fibonacci() function that uses a loop instead of recursion to calculate Fibonacci numbers.
#include<stdio.h>

int fibonacci(int n);

int main(void)
{
    int n;
    printf("Test Fibonacci() function\n");
    printf("Please enter an integer: ");
    while ((scanf("%d", &n) == 1) && n > 0)
    {
        printf("Fibonacci d = %d\n", fibonacci(n));
        printf("Enter an integer again n: ");
    }

}

int fibonacci(int n) {
    // Change result and adjust location of fib_n1 and fib_n2
    int fib_n1 = 1, fib_n2 = 1, result;
    if (n == 1 || n == 2)
        return 1;
    for (int i = 3; i <= n; i++)
    {
        result = fib_n1 + fib_n2;
        fib_n1 = fib_n2;
        fib_n2 = result;
    }
    return result;
    
}