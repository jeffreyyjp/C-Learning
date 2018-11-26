/* water_cal.c -- The mass of a single molecule of water is about 3.0*10^-23 grams. A quart of water is about 950 grams. Write a program that requests an amount of water, in quarts, and displays the number of water molecules in that amount. */
#include<stdio.h>
int main(void)
{
    double WATER_MASS = 3.0e-23;
    double QUART_WATER = 950.;
    double quarts;
    printf("Input an amount of water (in quarts): ");
    scanf("%f", &quarts);
    printf("There are %f molecules in %f quarts of water.\n", quarts * QUART_WATER / WATER_MASS, quarts);

	return 0;
}