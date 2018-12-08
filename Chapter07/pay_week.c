/* Write a program that requests the hours worked in a week and then prints the gross pay, the taxes, and the net pay. Assume the following:
a. Basic pay rate = $10.00/hr
b. Overtime (in excess of 40 hours) = time and a half
c. Tax rate: #15% of the first $300
20% of the next $150
25% of the rest
Use #define constants, and don't worry if the example does not conform to current tax law. */
#include<stdio.h>
#define PAY_RATE 10.00
#define OVERTIME 1.50
#define TAX_FIRST_300 0.15
#define TAX_NEXT_150 0.20
#define TAX_REST 0.25
int main(void)
{
    float hours_work;
    float payment, tax, net_pay;
    printf("Enter hour workded in a week: ");
    if (scanf("%f", &hours_work) != 1 || hours_work <= 0)
        printf("Enter wrong.\n");
    else
    {
        if (hours_work <= 40)
            payment = hours_work * PAY_RATE;
        else
            payment = 40 * PAY_RATE + (hours_work - 40) * PAY_RATE * OVERTIME;

        if (payment <= 300)
            tax = payment * TAX_FIRST_300;
        else if (payment > 300 && payment <= 450)
            tax = 300 * TAX_FIRST_300 + (payment - 300) * TAX_NEXT_150;
        else
            tax = 300 * TAX_FIRST_300 + 150 * TAX_NEXT_150 + (payment - 450) * TAX_REST;
        printf("total payment is %.2f, tax is %.2f, net payment is %.2f\n", payment, tax, payment - tax);
    }
    return 0;
}