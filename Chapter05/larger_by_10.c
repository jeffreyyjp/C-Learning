/* larger_by_10.c -- asks for an integer and then prints all the integers from(and including) that value up to (and including) a value larger by 10. */
#include<stdio.h>
#define LARGER_BY_10 10
int main(void)
{
    int intput_value, current_value;
    printf("Enter an integer value: ");
    scanf("%d", &intput_value);
    current_value = intput_value;
    while (current_value <= intput_value + LARGER_BY_10)
    {
        printf("%d ", current_value);
        current_value++;
    }
    printf("\n");

    return 0;
}