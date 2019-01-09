// The strncpy(s1, s2, n) function copies exactly n characters from s2 to s1, tuncating s2 or padding it with extra null characters as necessory. The target string may not be null-terminated if the length of s2 is n or more. The function returns s1. Write you own version of this function; call it mystrncpy(). Test the function in a complete program that uses a loop to provide input values for feeding to the function.
#include<stdio.h>
#include<string.h>
#define SIZE 20
char * mystrncpy(char *, char *, int);
char * s_gets(char * st, int n);
int main(int argc, char const *argv[])
{
    char src[SIZE];
    char dest[40] = "I am ";
    printf("Enter string to copy to %s\n", dest);
    while (*s_gets(src, SIZE) != '\0')
    {
        mystrncpy(dest, src, 10);
        printf("After copied, the dest string is %s\n", dest);
        printf("Enter string to copy to %s\n", dest);
    }

    return 0;
}

char * mystrncpy(char *dest, char *src, int n)
{
    int i;
    if (strlen(src) > n)
    {
        for (i = 0; i < n; i++)
            dest[i] = src[i];
    }
    else
    {
        for (i = 0; i < strlen(src); i++)
            dest[i] = src[i];
        for (; i < n; i++)
            dest[i] = '\0';
    }

    return dest;
}

char * s_gets(char * st, int n)
{
    char * ret_val;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (*st != '\n' && *st != '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}