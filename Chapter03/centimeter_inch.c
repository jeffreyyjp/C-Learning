/* centimeter_inch.c -- There are 2.54 centimeters to the inch. Write a program that asks you to enter your height in inches and then displays your height in centimeters. Or , if your prefer, ask for the height in centimeters and convert that to inches. */
#include<stdio.h>
int main(void)
{
    float INCHES_PER_CENTIMETERS = 1 / 2.54;
    float height;
    printf("Input your height in centimeters: ");
    scanf("%f", &height);
    printf("Convert centimeters to inches is %f\n", height * INCHES_PER_CENTIMETERS);

    return 0;
}