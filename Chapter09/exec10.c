// Generalize the to_binary() function of List 9.8 to a to_base_n() function that takes a second argument in the range 2-10. It then should print the number that is its first argument to the number base given by the second argument. For example, to_base_n(129, 8) would display 201, the base-8 equivalent of 129. Test the function in a complete program.
#include<stdio.h>
void to_base_n(unsigned long n, unsigned int base);

int main(void)
{
    unsigned long n;
    unsigned int base;
    printf("Please enter a decimal number and a base: ");
    while (scanf("%lu %d", &n, &base) == 2)
    {
        printf("Baes equivalent: ");
        to_base_n(n, base);
        putchar('\n');
        printf("Enter again or q for quit: ");
    }
    return 0;
}

void to_base_n(unsigned long n, unsigned int base)
{
    int r;
    r = n % base;
    if (n >= base)
    {
        to_base_n(n / base, base);
    }
    printf("%d", r);
}