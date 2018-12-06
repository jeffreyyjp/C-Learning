// even_odd.c -- Write a program that reads integers until 0 is entered. After input terminates, the porgram should report the total number of even integers (excluding the 0) entered, the average value of the even integers, the total number of odd integers entered, and the average value of the odd integers. */
#include<stdio.h>
int main(void)
{
    int input_num;
    int even_count = 0, event_sum = 0;
    int odd_count = 0, odd_sum = 0;
    printf("Enter integers until 0 is entered:\n");
    while ((scanf("%d", &input_num)) == 1)
    {
        if (input_num == 0)
            break;
        if (input_num % 2 == 0)
        {
            even_count++;
            event_sum+= input_num;
        }
        else
        {
            odd_count++;
            odd_sum += input_num;
        }
    }
    printf("total number of even integers is %d, average is %.2f\n", even_count, (float) event_sum / even_count);
    printf("total number of odd integers is %d, average is %.2f\n", odd_count, (float) odd_sum / odd_count);

    return 0;
}