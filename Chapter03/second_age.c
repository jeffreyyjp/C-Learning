/* There are approximately 3.156 * 10^7 seconds in a year. Input your age in years and then displays the equivalent number of seconds */
#include<stdio.h>
int main(void)
{
    double SECONDS_IN_YEAR = 3.156e7;
    int your_age_in_years;
    printf("Input your age in years: ");
    scanf("%d", &your_age_in_years);
    printf("Seconds in one year is %f\n", SECONDS_IN_YEAR);
    printf("You age displayed in seconds is %f\n", SECONDS_IN_YEAR * your_age_in_years);

    return 0;
}