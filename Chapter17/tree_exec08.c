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
static Pair SeekNode(const Item * pi, const Tree * ptree);
static bool AllNodeFull(const Trnode * root);
static bool NodeFull(const Trnode * root);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);

/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    return (ptree->root == NULL) ? true: false;
}

bool TreeIsFull(const Tree * ptree)
{
    return (ptree->size == MAXNODES) ? true: false;
}

int TreeNodeCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Pair look = SeekNode(pi, ptree);
    if (look.child == NULL)
    {
        if (TreeIsFull(ptree))
        {
            fprintf(stderr, "Tree is full\n");
            return false;
        }
        new_node = MakeNode(pi);
        if (new_node == NULL)
        {
            fprintf(stderr, "Couldn't create node\n");
            return false;
        }

        ptree->size++;
        if (ptree->root == NULL)
            ptree->root = new_node;
        else
        {
            if (ToLeft((*pi).petname, look.parent->list->petname))
                look.parent->left = new_node;
            else
                look.parent->right = new_node;
        }
    }
    else
    {
        return AddToList(pi, look.child->list);
    }

    return true;
}

bool InTree(const Item * pi, const Tree * ptree)
{
    // return (SeekNode(pi, ptree).child == NULL) ? false: true;
    Pair look = SeekNode(pi, ptree);
    if (look.child == NULL)
        return false;
    for (int i = 0; i < look.child->list->items; i++)
    {
        if (strcmp((*pi).petkind, look.child->list->entries[i].petkind))
            return true;
    }
    return false;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;

    look = SeekNode(pi, ptree);
    if (look.child == NULL)
        return false;
    
    if (look.parent == NULL)    /* delete root item */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

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
    ptree->size = 0;
}

/* local functions */
static void InOrder(const Trnode * root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        for (int i = 0; i < root->list->items; i++)
        (*pfun)(root->list->entries[i]);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static bool AddToList(const Item * pi, List * list)
{
    if (list->items == MAXITEMS)
        return false;
    list->entries[list->items] = *pi;
    return true;
}

static bool ToLeft(const char * ch1, const char * ch2)
{
    if (strcmp(ch1, ch2) < 0)
        return true;
    return false;
}

static bool ToRight(const char * ch1, const char * ch2)
{
    if (strcmp(ch1, ch2) > 0)
        return true;
    return false;
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

static Pair SeekNode(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;
    
    while (look.child != NULL)
    {
        if (ToLeft((*pi).petname, look.child->list->petname))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight((*pi).petname, look.child->list->petname))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else        /* must be same if not to left or right    */
            break;  /* look.child is address of node with item */
    }

    return look;    /* successful return */
}

static bool AllNodeFull(const Trnode * root)
{
    bool result = true;
    if (root != NULL)
    {
        if (NodeFull(root))
            result = (AllNodeFull(root->left) && AllNodeFull(root->right));
        else
            result = false;
    }

    return result;
}

static bool NodeFull(const Trnode * ptr)
{
    return ptr->items == MAXITEMS;
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

    free(temp);
}