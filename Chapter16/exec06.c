// Modify Listing 16.17 so that it uses an array of "struct names" elements(as defined after the listing) instead of an array of double. Use fewer elements, and initialize the array explicitly to a suitable selection of names.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct names {
    char first[40];
    char last[40];
} NAME;

#define NUM 15
void shownames(const NAME * ar, int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
    NAME staff[NUM] = {
        {"Amy", "Poehler"},
		{"Phyllis", "Smith"},
		{"Richard", "Kind"},
		{"Bill", "Hader"},
		{"Lewis", "Black"},
		{"Mindy", "Kaling"},
		{"Kaitlyn", "Dias"},
		{"Diane", "Lane"},
		{"Kyle", "MacLachlan"},
		{"Paula", "Poundstone"},
		{"Bobby", "Moynihan"},
		{"Paula", "Pell"},
		{"Dave", "Goelz"},
		{"Frank", "Oz"},
		{"Josh", "Cooley"},
    };
    puts("Here is the list of names:");
    shownames(staff, NUM);
    qsort(staff, NUM, sizeof(NAME), mycomp);
    puts("\nSorted list:");
    shownames(staff, NUM);
    return 0;
}

void shownames(const NAME * ar, int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s, %s\n", ar[index].last, ar[index].first);
    }
}

/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values */
    const NAME * a1 = (const NAME *) p1;
    const NAME * a2 = (const NAME *) p2;

    int c = strcmp(a1->last, a2->last);
    return c ? c : strcmp(a1->first, a2->first);
}