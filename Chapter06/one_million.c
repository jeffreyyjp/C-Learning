/* Chuckie Lucky won a million dollars, which he places in an account that earns 8% a year. On the last day of each year, Chuckie withdraws $ 100, 000. Write a program that finds out how many years it takes for Chuckie to empty his account. */
#include<stdio.h>
int main(void)
{
    double balance = 1000000;
    int year = 0;
    while (balance > 0)
    {
        balance *= 1.08;
        balance -= 100000;
        year += 1;
    }
    printf("After %d years, he empties his account\n", year);

    return 0;
}