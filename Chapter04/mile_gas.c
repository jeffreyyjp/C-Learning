/* mile_gas.c -- calculate and display the mile-per-gallon and liters-per-100-km value. */
#include<stdio.h>
#define LITERS_PER_GALLON 3.785
#define KILOMETERS_PER_MILE 1.609
int main(void)
{
    float miles, gallons, miles_per_gallon, liters_per_100_km;
    printf("Enter number of miles and number of gallons.\n");
    scanf("%f%f", &miles, &gallons);
    miles_per_gallon = miles / gallons;
    liters_per_100_km = 100. * (gallons * LITERS_PER_GALLON) / (miles * KILOMETERS_PER_MILE);
    printf("miles-per-gallon is %.1f\n", miles_per_gallon);
    printf("liters-per-100-km is %.1f\n", liters_per_100_km);

    return 0;
}