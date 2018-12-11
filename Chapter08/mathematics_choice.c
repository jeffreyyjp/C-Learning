// Write a program that shows you a menu offering you the choice of addition, subtraction, multiplication, or division. After getting your choice, the program asks for two numbers, then perfroms the requested operation. The program should accept only the offered menu choices. It should use type float for the numbers and allow the user to type again if he or she fails to enter a number. In the case of division, the program should prompt the user to enter a new value if 0 is entered as the value for the second number.
#include<stdio.h>
#include<ctype.h>
char get_choice(void);
char get_first(void);
float get_float(void);
void add(void);
void substract(void);
void multiply(void);
void divide(void);

int main(void)
{
    char choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                add();
                break;
            case 's':
                substract();
                break;
            case 'm':
                multiply();
                break;
            case 'd':
                divide();
                break;
            default:
                printf("Program error.\n!");
                break;
        }
    }
    printf("Bye.\n");
    return 0;
}

char get_choice(void)
{
    char choice;
    printf("Enter the operation of your choice:\n");
    printf("a. add        s. subtract\n");
    printf("m. multipy    d. divide\n");
    printf("q. quit\n");
    choice = get_first();
    while (!(choice == 'a' || choice == 's' || choice == 'm' || choice == 'd') && choice != 'q')
    {
        printf("Please respond with a, s, m, d or q.\n");
        choice = get_first();
    }

    return choice;
}

char get_first(void)
{
    char ch;
    while(isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    
    return ch;
}

float get_float(void)
{
    float num;
    char ch;
    while (scanf("%f", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }

    return num;
}

void add(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%.1f+ %.1f = %.1f\n", num1, num2, num1 + num2);
}

void substract(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
}

void multiply(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    printf("%.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
}

void divide(void)
{
    float num1, num2;
    printf("Enter first number: ");
    num1 = get_float();
    printf("Enter second number: ");
    num2 = get_float();
    while (num2 == 0.0)
    {
        printf("Enter a number other than 0: ");
        num2 = get_float();
    }
    printf("%.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
}