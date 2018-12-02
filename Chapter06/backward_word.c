/* backward_word.c -- Write a program that reads a single word into a character array and then prints the word backward. */
#include<stdio.h>
#include<string.h>
int main(void)
{
    char word[20];
    int len_word;
    printf("Enter a single word: ");
    scanf("%s", word);
    len_word = strlen(word);
    for (int i = len_word - 1; i >= 0; i--)
        printf("%c", word[i]);
    printf("\n");

    return 0;
}