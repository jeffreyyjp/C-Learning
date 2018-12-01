/* days_to_weeks.c -- asks the user to enter the number of days and then converts that value to weeks and days. */
#include<stdio.h>
#define DAYS_PER_WEEK 7
int main(void)
{
    int days, weeks, days_weeks;
    printf("Enter days to convert to weeks and days: ");
    scanf("%d", &days);
    while (days > 0)
    {
        weeks = days / DAYS_PER_WEEK;
        days_weeks = days % DAYS_PER_WEEK;
        printf("%d days are %d weeks, %d days.\n", days, weeks, days_weeks);
        printf("Enter days to convert to weeks and days: ");
        scanf("%d", &days);
    }
    return 0;
}