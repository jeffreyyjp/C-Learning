// Write a program that reads input as a stream of characters until encountering EOF. Have it report the average number of letters per word. Don't count whitespace as being letters in a word. Actually, punctuation shouldn't be counted either, but don't worry about that now. (If you do want to worry about it, consider using the ispunct() function from the ctype.h family.)
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
    int word_count = 0, character_count = 0;
    char ch;
    bool in_word = false;
    printf("Enter any characters:\n");

    while ((ch = getchar()) != EOF)
    {
        if (isalnum(ch))
        {
            character_count++;
            if (!in_word)
            {
                word_count++;
                in_word = true;
            }
        }
        else
            in_word = false;
        
    }
    printf("Total characters are %d, total words are %d.\n", character_count, word_count);
    printf("Average number of letters per word is %d.\n", character_count / word_count);

    return 0;
}