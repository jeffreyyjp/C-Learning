// Modify assumption a.in exercise 7 so that the program presents a menu of pay rates from which to choose. Use a 'switch' to select the pay rate.
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define OVERTIME 1.50
#define TAX_FIRST_300 0.15
#define TAX_NEXT_150 0.20
#define TAX_REST 0.25

char get_choice(void);
char get_first(void);
float get_payment(float hours_work, float pay_rate);
float get_tax(float payment);
int main(void)
{
    int choice;
    float pay_rate;
    float hours_work;
    float payment, tax, net_pay;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                pay_rate = 8.75;
                break;
            case 'b':
                pay_rate = 9.33;
                break;
            case 'c':
                pay_rate = 10.00;
                break;
            case 'd':
                pay_rate = 11.20;
                break;
            default:
                while (getchar() != '\n')
                    continue;
                printf("Please enter an integer 1 and 5\n");
                continue;
        }
        printf("Enter hour workded in a week: ");
        if (scanf("%f", &hours_work) != 1 || hours_work <= 0)
        {
            while (getchar() != '\n')
                continue;
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

char get_choice(void)
{
    int ch;
    printf("Enter the letter of your choices:\n");
    printf("a) $8.75/hr            b) $9.33/hr\n");
    printf("c) $10.00/hr           d) $11.20/hr\n");
    printf("q) quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    int ch;
    while (isspace((ch = getchar())))
        continue; 
    while (getchar() != '\n')
        continue;
    
    return ch;
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