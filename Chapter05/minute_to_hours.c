/* minute_to_hours.c -- converts time in minutes to time in hours and minutes. */
#include<stdio.h>
#define MINUTES_PER_HOUR 60
int main(void)
{
    int minutes, hours, minutes_hours;
    printf("Enter an amount of minutes: ");
    scanf("%d", &minutes);
    while (minutes > 0)
    {
        hours = minutes / MINUTES_PER_HOUR;
        minutes_hours = minutes % MINUTES_PER_HOUR;
        printf("%d minutes is %d hours and %d minutes.\n", minutes, hours, minutes_hours);
        printf("Enter an amount of minutes: ");
        scanf("%d", &minutes);
    }
}