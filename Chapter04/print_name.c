/* print_name.c -- ask your first name and last name, and then prints the names in the format last, first. */
#include<stdio.h>
int main(void)
{
    char first_name[20], last_name[20];
    printf("Enter your first name and last name: ");
    scanf("%s%s", first_name, last_name);
    printf("%s, %s\n", last_name, first_name);
    return 0;
}