// Modify assumption a.in exercise 7 so that the program presents a menu of pay rates from which to choose. Use a 'switch' to select the pay rate.
#include<stdio.h>
#include<stdbool.h>
#define OVERTIME 1.50
#define TAX_FIRST_300 0.15
#define TAX_NEXT_150 0.20
#define TAX_REST 0.25

float get_payment(float hours_work, float pay_rate);
float get_tax(float payment);
int main(void)
{
    int select_num;
    float pay_rate;
    bool quit = false;
    float hours_work;
    float payment, tax, net_pay;
    while (1)
    {
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr            2) $9.33/hr\n");
        printf("3) $10.00/hr           4) $11.20/hr\n");
        printf("5) quit\n");
        printf("*****************************************************************\n");
        scanf("%d", &select_num);
        switch (select_num)
        {
            case 1:
                pay_rate = 8.75;
                break;
            case 2:
                pay_rate = 9.33;
                break;
            case 3:
                pay_rate = 10.00;
                break;
            case 4:
                pay_rate = 11.20;
                break;
            case 5:
                quit = true;
                break;
            default:
                while (getchar() != '\n')
                    ;
                printf("Please enter an integer 1 and 5\n");
                continue;
        }
        if (quit)
            break;

        printf("Enter hour workded in a week: ");
        if (scanf("%f", &hours_work) != 1 || hours_work <= 0)
        {
            while (getchar() != '\n')
                ;
            printf("Enter wrong.\n");
        }
        else
        {
            payment = get_payment(hours_work, pay_rate);
            tax = get_tax(payment);
            printf("total payment is %.2f, tax is %.2f, net payment is %.2f\n", payment, tax, payment - tax);
        }
    }    
    return 0;
}

float get_payment(float hours_work, float pay_rate)
{
    float payment;
    if (hours_work <= 40)
        payment = hours_work * pay_rate;
    else
        payment = 40 * pay_rate + (hours_work - 40) * pay_rate * OVERTIME;
    return payment;
}

float get_tax(float payment)
{
    float tax;
    if (payment <= 300)
        tax = payment * TAX_FIRST_300;
    else if (payment > 300 && payment <= 450)
        tax = 300 * TAX_FIRST_300 + (payment - 300) * TAX_NEXT_150;
    else
        tax = 300 * TAX_FIRST_300 + 150 * TAX_NEXT_150 + (payment - 450) * TAX_REST;
    return tax;
}