/* stack.h -- interface for a stack */
#ifndef _STACK_H_
#define _STACK_H_
#include<stdbool.h>
/* INSERT ITEM TYPE HERE */
/* FOR EXAMPLE, */
// typedef int Item;  // for use_q.c
typedef struct item
{
    char ch;
} Item;

#define MAXSTACK 100

typedef struct stack
{
    Item items[MAXSTACK];
    int top; /* index of first empty slot */
} Stack;

/* operation:        initialize the stack */
/* precondition:     ps points to a stack */
/* postcondition:    stack is initialized to being empty */
void InitializeStack(Stack * ps);

/* operation:        check if stack is full */
/* precondition:     ps points to previously initialized stack */
/* postcondition:    return true if stack is full, else false */
bool StackIsFull(const Stack * ps);

/* operation:        check if stack is empty */
/* precondition:     ps points to previously initialized stack */
/* postcondition:    returns true if stack is empty, else false */
bool StackIsEmpty(const Stack * ps);

/* operation:        push item onto top of stack */
/* precondition:     item is to be placed on top of stack */
/*                   ps points to previously initialized stack */
/* postcondition:    if stack is not full, item is placed at top of */
/*                   stack and function returns true; otherwise stack */
/*                   is unchanged and function returns false */
bool Push(Item item, Stack * ps);

/* operation:        remove item from top of stack */
/* precondition:     ps points to previously initialized stack */
/* postcondition:    if stack is not empty, item at top of */
/*                   stack is copied to *pitem and deleted from */
/*                   stack, and function returns true; if the */
/*                   operation empties the stack, the stack is reset */
/*                   to empty. If the stack is empty to begin with, */
/*                   stack is unchanged and the function returns false */
bool Pop(Item *pitem, Stack * ps);

#endif