// Write a program that reads in up to 10 strings or to EOF, whicheever comes first. Have it offer the user a menu with five choices: print the original list of strings, print the strings in ASCII collating sequence, print the strings in order of increasing length, print the strings in order of the length of the first word in the string, and quit. Have the menu recycle until the user enters the quit request. The program, of course, should actually perform the promised tasks.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define SIZE 20
#define LIM 10
char get_choice(void);
char get_first(void);
void print_origin(char *[], int);
void ascii_order_print(char *[], int);
void print_incr_len(char *[], int);
void print_len_first_word(char *[], int);
int len_first_word(char *);
char * s_gets(char *, int);

int main(int argc, char const *argv[])
{
    int choice;
    int ct = 0;
    char str[LIM][SIZE];
    char *ptstr[LIM];
    printf("Enter up to ten strings, one for each line.\n");
    while (ct < LIM && s_gets(str[ct], SIZE) != NULL && str[ct][0] != '\0')
    {
        ptstr[ct] = str[ct];
        ct++;

    }

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                print_origin(ptstr, LIM);
                break;
            case 'b':
                ascii_order_print(ptstr, LIM);
                break;
            case 'c':
                print_incr_len(ptstr, LIM);
                break;
            case 'd':
                print_len_first_word(ptstr, LIM);
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }
    
    printf("Bye.\n");


    return 0;
}

char get_choice(void)
{
    int ch;
    printf("Enter the letter of your choices:\n");
    printf("a. print the original list of strings\n");
    printf("b. print the strings in ASCII collating sequence\n");
    printf("c. print the strings in order of increasing length\n");
    printf("d. print the strings in order of the length of the first word in the string\n");
    printf("q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'd') && ch != 'q')
    {
        printf("Please respond with a, b, c, d, or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    
    return ch;
}

void print_origin(char *strs[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n", strs[i]);

    printf("\n");
}

void ascii_order_print(char *strs[], int n)
{
    char * temp;
    char *sorted[n];
    
    // set another to make sure strs keep unchanged.
    for (int i = 0; i < n; i++)
        sorted[i] = strs[i];

    // sort arrays of strings.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(sorted[i], sorted[j]) > 0)
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // print sorted arrays of strings.
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sorted[i]);
    }

    printf("\n");
}

void print_incr_len(char *strs[], int n)
{
    char * temp;
    char *sorted[n];
    
    // set another to make sure strs keep unchanged.
    for (int i = 0; i < n; i++)
        sorted[i] = strs[i];

    // sort arrays of strings.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(sorted[i]) > strlen(sorted[j]))
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // print sorted arrays of strings.
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sorted[i]);
    }

    printf("\n");
}

void print_len_first_word(char *strs[], int n)
{
    char * temp;
    char *sorted[n];
    
    // set another to make sure strs keep unchanged.
    for (int i = 0; i < n; i++)
        sorted[i] = strs[i];

    // sort arrays of strings.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (len_first_word(sorted[i]) > len_first_word(sorted[j]))
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // print sorted arrays of strings.
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sorted[i]);
    }

    printf("\n");
}

int len_first_word(char * str)
{
    int count = 0;
    bool reached_first_word = false;
    while (*str)
    {
        if (!isspace(*str))
        {
            reached_first_word = true;
            count++;
        }
        else
        {
            if (reached_first_word)
                break;
        }
        str++;
    }

    return count;
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        while (*str != '\n' && *str != '\0')
            str++;
        if (*str == '\n')
            *str = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}
