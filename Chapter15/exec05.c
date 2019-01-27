// Write a function that rotates the bits of an unsigned int by a specified number of bits to the left. For instance, rotate_l(x, 4) would move the bits in x four places to the left, and the bits lost from the left end would reappear at the right end. That is the bit moved out of the high-order position is placed in the low-order position. Test the function in a program.
#include<stdio.h>
#include<limits.h>

const unsigned int BITS = CHAR_BIT * sizeof(unsigned int);
const unsigned int LEFT_MASK = 1 << (BITS - 1);

int rotate_l(unsigned int, int);

int main(int argc, char const *argv[])
{
    unsigned int value, num;
    unsigned int rotated;
    printf("Enter a integer: ");
    while (scanf("%d", &value) == 1)
    {
        printf("Enter a number to rotate: ");
        while (scanf("%d", &num) == 1)
        {
            printf("Before rotation: ");
            for (int i = 0; i < BITS; i++)
            {
                if ((value << i) & LEFT_MASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            rotated = rotate_l(value, num);
            printf("After rotation: ");
            for (int i = 0; i < BITS; i++)
            {
                if ((rotated << i) & LEFT_MASK)
                    putchar('1');
                else
                    putchar('0');
            }
            putchar('\n');
            printf("Enter a number to rotate: ");
        }
        while (getchar() != '\n')
            continue;
        printf("Enter a integer: ");
    }
    return 0;
}

int rotate_l(unsigned int value, int num)
{
    int left_bit;
    for (int i = 0; i < num; i++)
    {
        left_bit = value & LEFT_MASK;
        value <<= 1;
        if (left_bit)
            value |= 1;
    }

    return value;
} 
