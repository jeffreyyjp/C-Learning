// Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in the order entered, then alphabetized by title, and then in order of increased value.
#include<stdio.h>
#include<string.h>
char * s_gets(char *, int);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    /* data */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void title_sort_print(struct book[], int);
void value_sort_print(struct book[], int);

int main(void)
{
    struct book library[MAXBKS];
    struct book temp[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press (enter) at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%0.2f\n", library[index].title, library[index].author, library[index].value);
        puts("");
        // print according alphabetized by title
        printf("Here is the list of your books ordered by title:\n");
        title_sort_print(library, count);
        puts("");
        printf("Here is the list of your books ordered by value:\n");
        value_sort_print(library, count);
    }
    else
    {
        printf("No books? Too bad.\n");
    }

    return 0;
}

void title_sort_print(struct book books[], int n)
{
    struct book temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(books[i].title, books[j].title) > 0)
            {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s by %s: $%0.2f\n", books[i].title, books[i].author, books[i].value);   
    }
}

void value_sort_print(struct book books[], int n)
{
    struct book temp;
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (books[i].value > books[j].value)
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s by %s: $%0.2f\n", books[i].title, books[i].author, books[i].value);   
    }
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
