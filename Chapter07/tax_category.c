/* The 1988 United States Federal Tax Schedule was the simplest in recent times. It had four categories, and each category had two rates. Here is a summary (dollar amounts are taxable income):
Category                    Tax
Single                      15% of first $17,850 plus 28% of excess
Head of Household           15% of first $23,900 plus 28% of excess
Married, Joint              15% of first $29,750 plus 28% of excess
Married, Separate           15% of first $14,875 plus 28% of excess
*/
#include<stdio.h>
#define SINGLE 1
#define HEAD_OF_HOUSEHOLD 2
#define MARRIED_JOINT 3
#define MARRIED_SEPARATE 4
#define QUIT 5
int main(void)
{
    int category;
    float income, base, taxes;
    while (1)
    {
        printf("1) Single  2) Head of Household  3) Married, Joint  4) Married, Separate.\n");
        printf("Enter your tax category(1-4) or 5 to quit: ");
        scanf("%d", &category);

        switch (category)
        {
            case SINGLE:
                base = 17850.0;
                break;
            case HEAD_OF_HOUSEHOLD:
                base = 23900.0;
                break;
            case MARRIED_JOINT:
                base = 29750.0;
                break;
            case MARRIED_SEPARATE:
                base = 14785.0;
                break;
            case QUIT:
                printf("Bye.\n");
                return 0;
            default:
                while (getchar() != '\n')
                    ;
                printf("Invalid input: please inter an integer 1 to 5.\n");
                continue;
        }
        printf("Enter your taxable income: ");
        while (scanf("%f", &income) != 1 || income < 0)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input, please enter a positive number.\n");
            printf("Enter your taxable income: ");
        }
        if (income > base)
            taxes = 0.15 * base + (income - base) * 0.28;
        else
            taxes = 0.15 * base;
        printf("You will pay %f taxes.\n\n", taxes);
    }
    
    return 0;
}