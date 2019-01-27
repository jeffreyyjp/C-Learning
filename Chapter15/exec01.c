/* Write a function that converts a binary string to a numberic value. That is, if you have char * pbin = "01001001";
you can pass pbin as an argument to the function and have the function return an int value of 25.
Note: "01001001" actually is 73 */
#include<stdio.h>

int binary2int(const char *);

int main(void)
{
    char * pbin = "01001001";
    printf("%s in base 10 is %d.\n", pbin, binary2int(pbin));
    return 0;
}

int binary2int(const char * st)
{
    int ret_val = 0;
    while (*st != '\0')
    {
        ret_val <<= 1;
        if (*st == '1')
            ret_val |= 1;
        st++;
    }

    return ret_val;
}