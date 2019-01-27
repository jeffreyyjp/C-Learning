// Write a program that reads two binary strings as command-line arguments and prints the results of applying the ~ operator to each number and the results of applying the & , |, and ^ operators to the pair. Show the results as binary string. (If you don't have a command-line environment available, have the program read the strings interactively.);
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int binary2int(const char * st);
char * itobs(int n, char * ps);

int main(int argc, char const *argv[])
{
    int m, n;
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    if (argc != 3)
    {
        printf("Usage: %s string string.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    m = binary2int(argv[1]);
    n = binary2int(argv[2]);
    printf("%d %d\n", m, n);
    printf("~%s = %s\n", argv[1], itobs(~m, bin_str));
    printf("~%s = %s\n", argv[2], itobs(~n, bin_str));

    printf("%s & %s = %s\n", argv[1], argv[2], itobs(m & n, bin_str));
    printf("%s | %s = %s\n", argv[1], argv[2], itobs(m | n, bin_str));
    printf("%s ^ %s = %s\n", argv[1], argv[2], itobs(m ^ n, bin_str));
    return 0;
}

int binary2int(const char * st)
{
    int ret_val = 0;
    while (*st != '\0')
    {
        ret_val <<= 1;
        if (*st != '0' && *st != '1')
        {
            fprintf(stderr, "Error: input string is not binary.\n");
            exit(EXIT_FAILURE);
        }
        if (*st == '1')
            ret_val |= 1;
        st++;
    }

    return ret_val;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';     // assume ASCII or similar
    }
    ps[size] = '\0';

    return ps;
}
