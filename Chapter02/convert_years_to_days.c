// convert_years_to_days.c -- Convert years to days, and don't care about fractional years and leap years.
#include<stdio.h>
int main(void)
{
    int years;
    int days;
    years = 27;
    days = years * 365;
    printf("Your years of age is %d, days of age is %d.\n", years, days);

    return 0;
}