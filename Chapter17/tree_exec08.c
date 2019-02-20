/* tree.c -- tree support functions */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree_exec08.h"

/* local data type */
typedef struct pair
{
    Trnode * parent;
    Trnode * child;
} Pair;

/* prototypes for local functions */
static Trnode * MakeNode(const Item * pi);
static List * MakeList(const Item * pi);
static bool ToLeft(const char * ch1, const char * ch2);
static bool ToRight(const char * ch1, const char * ch2);
static bool AddToList(const Item * pi, List * list);
static void InOrder(const Trnode * root, void (* pfun)(Item item));
static bool NodeIsFull(const Tree * ptree);
static Pair SeekNode(const char * name, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteFromList(const Item * pi, List * list);
static void DeleteAllNodes(Trnode * ptr);

/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->node_size = 0;
    ptree->item_size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    return (ptree->root == NULL) ? true: false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (NodeIsFull(ptree))
        return (MAXNODES * MAXITEMS == ptree->item_size) ? true: false;
    return false;
}

static bool NodeIsFull(const Tree * ptree)
{
    return (ptree->node_size == MAXNODES) ? true: false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->item_size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Pair look;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    look = SeekNode((*pi).petname, ptree);
    if (look.child == NULL)
    {
        if (NodeIsFull(ptree))
        {
            fprintf(stderr, "Node is full, can't create new node\n");
            return false;
        }
        new_node = MakeNode(pi);
        if (new_node == NULL)
        {
            fprintf(stderr, "Couldn't create node\n");
            return false;
        }

        ptree->node_size++;
        ptree->item_size++;
        if (ptree->root == NULL)
            ptree->root = new_node;
        else if (ToLeft((*pi).petname, look.parent->list->petname))
            look.parent->left = new_node;
        else
            look.parent->right = new_node;
    }
    else if (AddToList(pi, look.child->list))
    {
        ptree->item_size++;
        return true;
    }
    else
    {
        fprintf(stderr, "list is full\n");
        return false;
    }

    return true;
}

Trnode * InTree(const char * name, const Tree * ptree)
{
    return SeekNode(name, ptree).child;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;

    look = SeekNode((*pi).petname, ptree);
    if (look.child == NULL)
        return false;
    
    ptree->item_size--;
    if (look.child->list->items == 1) /* Node holding list has only one item, drop entire Node */
    {
        ptree->node_size--;
        if (look.parent == NULL)
            DeleteNode(&ptree->root);
        else if (look.parent->left = look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
    }
    else
        DeleteFromList(pi, look.child->list);

    return true;
}

void Traverse(const Tree  * ptree, void(* pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->node_size = 0;
    ptree->item_size = 0;
}

/* local functions */
static void InOrder(const Trnode * root, void (*pfun)(Item item))
{
    int count;
    if (root != NULL)
    {
        count = root->list->items;
        InOrder(root->left, pfun);
        for (int i = 0; i < count; i++)
            (*pfun)(root->list->entries[i]);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * ptr)
{
    Trnode * pright;

    if (ptr != NULL)
    {
        pright = ptr->right;
        DeleteAllNodes(ptr->left);
        free(ptr->list);
        free(ptr);
        DeleteAllNodes(pright);
    }
}

static bool AddToList(const Item * pi, List * list)
{
    if (list->items == MAXITEMS)
        return false;
    list->entries[list->items] = *pi;
    list->items++;
    return true;
}

static bool ToLeft(const char * ch1, const char * ch2)
{
    return (strcmp(ch1, ch2) < 0) ? true: false;
}

static bool ToRight(const char * ch1, const char * ch2)
{
    return (strcmp(ch1, ch2) > 0) ? true: false;
}

static List * MakeList(const Item * pi)
{
    List * new_list;
    new_list = (List *) malloc(sizeof(List));
    if (new_list != NULL)
    {
        new_list->entries[0] = *pi;
        new_list->items = 1;
        strcpy(new_list->petname, (*pi).petname);
    }

    return new_list;
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;
    List * new_list;
    new_list = MakeList(pi);
    if (new_list == NULL)
        return NULL;
    
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->list = new_list;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static Pair SeekNode(const char * name, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;
    
    while (look.child != NULL)
    {
        if (ToLeft(name, look.child->list->petname))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(name, look.child->list->petname))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* must be same if not to left or right    */
            break;  /* look.child is address of node with item */
    }

    return look;    /* successful return */
}

static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node */
{
    Trnode * temp;
    
    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
    }
    else /* deleted node has two children */
    {
        temp = (*ptr)->left;
        /* find where to reattach right subtree */
        while (temp->right != NULL)
            temp = temp->right;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
    }

    free(temp->list);
    free(temp);
}

static void DeleteFromList(const Item * pi, List * list)
{
    if (pi == NULL || list == NULL)
        return;
    
    int count = list->items;
    int index;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(pi->petkind, list->entries[i].petkind) == 0)
        {
            index = i;
            break;
        }
    }
    for (int i = index; i < count - 1; i++)
        strcpy(list->entries[i].petkind, list->entries[i+1].petkind);
    list->items--;
}