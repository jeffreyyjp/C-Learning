// Deivse a program that counts the number of characters in its input up to the end of file.
#include<stdio.h>
int main(void)
{
    int num = 0;
    printf("Enter any characters for counting.\n");
    while (getchar() != EOF)
        num++;
    printf("Total number of characters is %d\n", num);
    return 0;
}