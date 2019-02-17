/* stack.c -- the Stack type implementation */
#include<stdio.h>
#include<stdbool.h>
#include "stack.h"

void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

bool StackIsFull(const Stack * ps)
{
    return (ps->top == MAXSTACK);
}

bool StackIsEmpty(const Stack * ps)
{
    return (ps->top == 0);
}

bool Push(Item item, Stack * ps)
{
    if (StackIsFull(ps))
        return false;
    ps->items[ps->top++] = item;
    return true;
}

bool Pop(Item *pitem, Stack * ps)
{
    if (StackIsEmpty(ps))
        return false;
    *pitem = ps->items[--ps->top];
    return true;
}

