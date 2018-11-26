/* volume_measurements.c -- convert volume between pint, cup, ounce, tablespoon and teaspoons. */
#include<stdio.h>
int main(void)
{
    float PINTS_PER_CUP = 0.5;
    float OUNCES_PER_CUP = 8.;
    float TABLESPOONS_PER_CUP = OUNCES_PER_CUP * 2;
    float TEASPOONS_PER_CUP = TABLESPOONS_PER_CUP * 3;
    float cups;
    printf("Input a volume in cups: ");
    scanf("%f", &cups);
    printf("Convert to pints is %f\n", PINTS_PER_CUP * cups);
    printf("Convert to ounces is %f\n", OUNCES_PER_CUP * cups);
    printf("Convert to tablespoons is %f\n", TABLESPOONS_PER_CUP * cups);
    printf("Convert to teaspoons is %f\n", TEASPOONS_PER_CUP * cups);

    return 0;
}