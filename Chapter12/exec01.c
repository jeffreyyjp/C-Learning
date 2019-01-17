// Rewrite the program in Listing 12.4 so that it does not use global variables.
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int units; /* an optional redeclaration */

    printf("How many pounds to a firkin of butter?\n");
    while (scanf("%d", &units) == 1 && units != 56)
        printf("No luck, my friend. Try again.\n");
    printf("You must have looked it up!\n");
    
    return 0;
}