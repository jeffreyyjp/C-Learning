/* lowercase_letters.c -- Wirte a program that creates an array with 26 elements and stores the 26 lowercase letters in it. Also have it show the array contents. */
#include<stdio.h>
#include<string.h>
int main(void)
{
    const int LETTERS_LENGTH = 26;
    char letters[LETTERS_LENGTH], letter = 'a';
    for (int i = 0; i < LETTERS_LENGTH; i++, letter++)
    {
        letters[i] = letter;
    }
    
    for (int i = 0; i < LETTERS_LENGTH; i++)
        printf("%c ", letters[i]);
    printf("\n");
    printf("Letters has %zd letters, occupied %zd memory cells\n", strlen(letters), sizeof letters);

    return 0;
}