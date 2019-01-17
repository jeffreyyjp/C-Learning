// compile with pe12-2b.c
#include "pe12-2a.h"
#include <stdio.h>

static int mode = 0;
static double distance;
static double fuel_consumption;

void set_mode(int set_mode)
{
    if (set_mode != 0 && set_mode != 1)
    {
        if (mode == 0)
            printf("Invalid mode specified. Mode 0(metric) used.\n");
        else
            printf("Invalid mode specified. Mode 1(US) used.\n");
    }
    else
        mode = set_mode;
}

void get_info(void)
{
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel_consumption);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel_consumption);
    }
}

void show_info(void)
{
    double per_consumption;
    if (mode == 0)
    {
        per_consumption = fuel_consumption / distance * 100;
        printf("Fuel consumption is %.2lf liters per 100 km.\n", per_consumption);
    }
    else
    {
        per_consumption = distance / fuel_consumption;
        printf("Fuel consumption is %.1lf miles per gallon.\n", per_consumption);
    }
}