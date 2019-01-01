// getsputs.c -- using gets() and puts()
#include<stdio.h>
#define STLEM 81
int main(void)
{
    char words[STLEM];

    puts("Enter a string, please.");
    gets(words);
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    return 0;
}