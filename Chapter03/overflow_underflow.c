/* overflow_underflow.c -- Find out what your system does with integer overflow, floating-point overflow, and floating-point underflow by using the experimental approach. */
#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(void)
{
    int int_overflow;
    float float_overflow, float_underflow;
    int_overflow = INT_MAX + 1;
    float_overflow = FLT_MAX * 2;
    float_underflow = FLT_MIN / 2;

    printf("integer overflow by adding max value with 1: ");
    printf("max int value is %d, reuslt by add 1 is %d\n", INT_MAX, int_overflow);
    printf("float overflow by multiplying 2: ");
    printf("max float value is %f, result by multiplying 2 is %f\n", FLT_MAX, float_overflow);
    printf("float underflow by dividing 2: ");
    printf("min float value is %f, result by dividing 2 is %f\n", FLT_MIN, float_underflow);

    return 0;
}