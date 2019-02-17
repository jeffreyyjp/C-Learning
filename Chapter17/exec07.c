// Write a program that opens and reads a text file and records how many times each words occurs in the file. Use a binary search tree modified to store both a word and the number of times it occurs. After the program has read the file, it should offer a menu with three choices. The first is to list all the words along with the number of occurrences. The second is to let you enter a word, with the program reporting how many times the word occurred in the file. The third choice is to quit.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "tree_exec07.h"

char get_choice(void);
char get_first(void);
void show_word(const Tree * words);
void search_word(const Tree * words);
char * s_gets(char * st, int n);
void printitem(Item item);

int main(int argc, char const *argv[])
{
    Tree words;
    Item temp;

    FILE * fp;
    char word[MAX];
    int choice;

    InitializeTree(&words);
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%40s", word) == 1)
    {
        temp.count = 1;
        strcpy(temp.word, word);
        AddItem(&temp, &words);
    }

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'l':
                show_word(&words);
                break;
            case 's':
                search_word(&words);
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    puts("Bye!");

    return 0;
}

void show_word(const Tree * words)
{
    Traverse(words, printitem);
}

void search_word(const Tree * words)
{
    Item temp;
    char str[MAX];
    printf("Enter any word: ");
    s_gets(str, MAX);
    strcpy(temp.word, str);
    printf("%s has occurred %d times\n", str, SearchedItemCount(&temp, words));
}

void printitem(Item item)
{
    printf("%s has occurred %d times\n", item.word, item.count);
}

char get_choice(void)
{
    int ch;
    printf("l) list all the words along with the number of occurrences\n");
    printf("s) enter word to get numbers of occurrences\n");
    printf("q) quit\n");
    ch = get_first();
    while (ch != 'l' && ch != 's' && ch != 'q')
    {
        printf("Please respond with l , s or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n') continue;

    return ch;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}