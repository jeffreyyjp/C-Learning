/* name_len.c -- print first name and last name and their length of characters. */
#include<stdio.h>
#include<string.h>
int main(void)
{
    char first_name[20], last_name[20];
    int len_first, len_last;
    printf("Enter your first name and last name: ");
    scanf("%s%s", first_name, last_name);
    len_first = strlen(first_name);
    len_last = strlen(last_name);
    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n", len_first, len_first, len_last, len_last);
    printf("%-*d %-*d\n", len_first, len_first, len_last, len_last);

    return 0;
}