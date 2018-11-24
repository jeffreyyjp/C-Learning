// printf_name.c -- Print name using different printf function implemention.
#include<stdio.h>
int main(void)
{
    printf("%s %s\n", "Jeffrey", "Yang");
    printf("%s\n%s\n", "Jeffrey", "Yang");
    printf("%s", "Jeffrey");
    printf(" %s\n", "Yang");

    return 0;
}