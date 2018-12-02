/* Write a program that reads eight integers into an array and then prints them in reverse order. */
#include<stdio.h>
#define LEN 8
int main(void)
{
    int i;
    int numbers[LEN];
    printf("Enter eight integers: ");
    for (i = 0; i < LEN; i++)
        scanf("%d", &numbers[i]);
    for (i--; i >= 0; i--)
        printf("%d ", numbers[i]);
    printf("\n");
    
    return 0;
}