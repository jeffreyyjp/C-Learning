/* print_first_name.c -- using different style to display your first name */
#include<stdio.h>
#include<string.h>
int main(void)
{
    char first_name[20];
    int name_num;
    printf("Enter your first name: ");
    scanf("%s", first_name);
    name_num = strlen(first_name);
    printf("\"%s\"\n", first_name);
    printf("\"%20s\"\n", first_name);
    printf("\"%-20s\"\n", first_name);
    printf("%*s\n", name_num + 3, first_name);
}