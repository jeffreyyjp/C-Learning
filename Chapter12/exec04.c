// Write and test in a loop a function that returns the number of times it has been called.
#include<stdio.h>
static int count = 0;
void called_func(void);
int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < 5; i++)
        called_func();
    printf("called_fun has been called %d times.\n", count);
    return 0;
}

void called_func(void)
{
    count++;
}
