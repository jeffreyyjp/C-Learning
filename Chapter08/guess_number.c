// Modify the guessing program so that it uses a more intelligent guessing strategy.
#include<stdio.h>
int main(void)
{
    int initial_value = 50;
    int guess;
    char ch;
    printf("Enter a number between 1 and 100 to guess(0 to quit): \n");
    while (1)
    {
        if (scanf("%d", &guess) != 1 || (guess < 0 || guess > 100))
        {
            printf("Invalid input, enter between 1 and 100(0 to quit): \n");
            while ((ch = getchar()) != '\n')
                continue;
            continue;
        }
        if (guess == initial_value)
        {
            printf("OK, you are right.\n");
            break;
        }
        if (guess == 0)
        {
            printf("Bye.\n");
            break;
        }
        if (guess < initial_value)
        {
            printf("Guess higher, please.\n");
            continue;
        }
        if (guess > initial_value)
        {
            printf("Guess lower, please.\n");
            continue;
        }
    }
    return 0;
}