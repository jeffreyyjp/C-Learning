/* Write a program that initializes an array-of-double and then copies the contents of the array into three other arrays. (All four arrays should be declared in the main program.) To make the first copy, use a function with array notation. To make the second copy, use a function with pointer notation and pointer incrementing. Have the first two functions takes as arguments the name of the target array, the name of the source array, and the number of elements to be copied. Have the third function take as arguments the name of the target, the name of the source, and a pointer to the element following the last element of the source. That is, the function calls would look like this, given the following declarations:

double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
double target1[5];
double target2[5];
double target3[5];
copy_arr(target1, source, 5);
copy_ptr(target2, source, 5);

copy_ptrs(target3, source, source + 5);
*/
#include<stdio.h>
#define LENGTH 5

void copy_arr(double target[], double source[], int n);
void copy_ptr(double *target, double *source, int n);
void copy_ptrs(double *target, double *source, double *endsource);
int main(void)
{
    double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[LENGTH];
    double target2[LENGTH];
    double target3[LENGTH];
    // array copy using array natation.
    printf("Copy to target1 using array notation.\n");
    copy_arr(target1, source, LENGTH);
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", target1[i]);
    printf("\n");

    // array copy using pointer natation.
    printf("Copy to target2 using pointer notation.\n");
    copy_ptr(target2, source, LENGTH);
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", target2[i]);
    printf("\n");
    
    // array copy using start pointer and end pointer.
    printf("Copy to target3 using arguments the name of the target, the name of the source, and a pointer to the element following the last element of the source.\n");
    copy_ptrs(target3, source, source + LENGTH);
    for (int i = 0; i < LENGTH; i++)
        printf("%.1lf ", target3[i]);
    printf("\n");

    return 0;
}

// using array notation to copy array.
void copy_arr(double target[], double source[], int n)
{
    for (int i = 0; i < n; i++)
    {
        target[i] = source[i];
    }
}

// using pointer notation to copy array.
void copy_ptr(double *target, double *source, int n)
{
    for (int i = 0; i < n; i++, target++, source++)
    {
        *target = *source;
    }
}

// using start pointer and end pointer to copy array.
void copy_ptrs(double *target, double *source, double *endsource)
{
    for (double * ptr = source; ptr < endsource; ptr++, target++)
    {
        *target = *ptr;
    }
}