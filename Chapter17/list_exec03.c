/* list.c -- functions supporting list operatons */
#include<stdio.h>
#include<stdlib.h>
#include "list_exec03.h"

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    // *plist = NULL;
    plist->items = 0;
}

/* returns true if list if empty */
bool ListIsEmpty(const List * plist)
{
    return (plist->items == 0);
}

/* returns true if list if full */
bool ListIsFull(const List * plist)
{
    return (plist->items == MAXSIZE);
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

/* create node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItem(Item item, List * plist)
{
    if (plist->items < MAXSIZE)
    {
        plist->entries[plist->items] = item;
        (plist->items)++;
        return true;
    }
    else
        return false;

}

/* visit each node and executes function pointed to by pfun */
void Traverse(const List * plist, void(* pfun)(Item item))
{
    for (int i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);
}

/* free memory allocated by malloc() */
/* set list pointer to NULL */
void EmptyTheList(List * plist)
{
    plist->items = 0;
}