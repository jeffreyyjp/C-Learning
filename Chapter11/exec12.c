// Write a program that reads input up to EOF and reports the number of words, the number of uppercase letters, the number of lowercase letters, the number of punctuation characters, and the number of digits, Use the ctype.h family of functions.
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
    char c, prev = '\n';
    long n_chars = 0L;
    int n_words = 0;
    int n_upper_letters = 0;
    int n_lower_letters = 0;
    int n_punc_chars = 0;
    int n_digits = 0;
    bool inword = false;

    printf("Enter text to be displayed (EOF to terminate):\n");
    while ((c = getchar()) != EOF)
    {
        n_chars++;
        if (isupper(c))
            n_upper_letters++;
        if (islower(c))
            n_lower_letters++;
        if (ispunct(c))
            n_punc_chars++;
        if (isdigit(c))
            n_digits++;

        if (!isspace(c) && !inword)
            n_words++;
            inword = true;
        if (isspace(c))
            inword = false;
    }

    printf("words = %d, uppers = %d, lowers = %d, puncs = %d, digits = %d.\n", n_words, n_upper_letters, n_lower_letters, n_punc_chars, n_digits);

    return 0;
}
