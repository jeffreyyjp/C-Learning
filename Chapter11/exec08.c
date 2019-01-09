// Write a function called string_in() that takes two string pointers as arguments. If the second string is contained in the first string, have the function return the address at which the contained string begins. For instance, string_in("hats", "at") would return the address of the a in hats. Otherwise, have the function return the null pointer. Test the function in a complete program that uses a loop to provide input values for feeding to the function.
#include<stdio.h>
#include<string.h>
#define SIZE 11
char * string_in(char *, char *);
char * s_gets(char * st, int n);
int main(int argc, char const *argv[])
{
    char parentstr[SIZE];
    char substr[SIZE];
    printf("Enter parent str and sub str.\n");
    while (*s_gets(parentstr, SIZE) != '\0' && *s_gets(substr, SIZE) != '\0')
    {
        if (string_in(parentstr, substr))
        {
            printf("%s is in %s\n", substr, parentstr);
            printf("%s.\n", string_in(parentstr, substr));
        }
        else
            printf("%s is not in %s\n", substr, parentstr);
    }
    

    return 0;
}

char * string_in(char * parentstr, char * substr)
{
    char * result;
    char * temp = substr;
    while (*parentstr)
    {
        if (*parentstr == *temp)
        {
            parentstr++;
            temp++;
        }
        else
        {
            temp = substr;
            result = ++parentstr;
        }
        if (*temp == '\0')
            break;
    }
    
    if (*temp != '\0')
        return NULL;

    return result;
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
