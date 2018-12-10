// Wirte a program that reads input as a stream of characters until encountering EOF. Have it report the number of uppercase letters, the number of lowercase letters, and the number of other characters in the input. You may assume that the numeric values for the lowercase letters are sequential and assume the same for uppercase. Or, more portably you can use appropriate classification functions from the ctype.h library.
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int upper_count = 0, lower_count = 0, other_count = 0;

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upper_count++;
        else if (islower(ch))
            lower_count++;
        else
            other_count++;
    }
    printf("number of uppercase letters is %d, number of lowercase letters is %d, number of other characters is %d.\n", upper_count, lower_count, other_count);

    return 0;
}