/* Write a program that prints a table with each line giving an integer, its square, and its cube. Ask the user to input the lower and upper limits for the table. */
#include<stdio.h>
int main(void)
{
    int low, high;
    printf("Enter low and high of the table: ");
    scanf("%d%d", &low, &high);
    for (int i = low; i < high; i++)
        printf("%d %d %d\n", i, i * i, i * i * i);
    
    return 0;
}