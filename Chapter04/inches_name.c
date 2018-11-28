/* inches_name.c -- display your height and your name. */
#include<stdio.h>
int main(void)
{
    float height;
    char name[20];
    printf("Enter your height(centimeter) and name: ");
    scanf("%f%s", &height, name);
    printf("%s, you are %0.2f meters tall\n", name, height / 100);

    return 0;
}