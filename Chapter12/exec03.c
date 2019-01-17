// Redesign the program described in Programming Exercise 2 so that it uses only automatic variables. Have the program offer the same user interface--that is, it should prompt the user to enter a mode, and so on. You'll have to come up with a different set of function calls, however.
#include<stdio.h>
#include<stdbool.h>
void cal_consumption(int mode);
bool check_mode(int mode, int last_mode);
int main(void)
{
    int mode;
    int last_mode = 0;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        if (!check_mode(mode, last_mode))
            mode = last_mode;
        last_mode = mode;
        cal_consumption(mode);
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf( "(-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}

void cal_consumption(int mode)
{
    double distance, fuel_consumption;
    double per_consumption;
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel_consumption);
        per_consumption = fuel_consumption / distance * 100;
        printf("Fuel consumption is %.2lf liters per 100 km.\n", per_consumption);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel_consumption);
        per_consumption = distance / fuel_consumption;
        printf("Fuel consumption is %.1lf miles per gallon.\n", per_consumption);
    }
}

bool check_mode(int mode, int last_mode)
{
    if (mode != 0 && mode != 1)
    {
        if (last_mode == 0)
            printf("Invalid mode specified. Mode 0(metric) used.\n");
        else
            printf("Invalid mode specified. Mode 1(US) used.\n");
        return false;
    }
    return true;
}