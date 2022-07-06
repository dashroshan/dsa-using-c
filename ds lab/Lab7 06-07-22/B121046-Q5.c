// Reverse a linked list without using stack by manipulation of pointers

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

node *create(void);
void reverse(node **);
void display(node *, char *);

int main()
{
    node *llHead = create();
    display(llHead, "Original");
    reverse(&llHead);
    display(llHead, "Reversed");
    return (0);
}

node *create(void)
{
    int num, c;
    node *first = (node *)malloc(sizeof(node)), *llptr = first;
    printf("Enter elements: ");
    scanf("%d%c", &llptr->info, &c);
    while (1)
    {
        if (c != ' ')
        {
            llptr->link = NULL;
            break;
        }
        scanf("%d%c", &num, &c);
        llptr->link = (node *)malloc(sizeof(node));
        llptr = llptr->link;
        llptr->info = num;
    }
    return first;
}

void display(node *first, char *text)
{
    if (first == NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    printf("%s linked list: ", text);
    node *llptr = first;
    while (1)
    {
        printf("%d", llptr->info);
        if (llptr->link == NULL)
            break;
        else
            llptr = llptr->link;
        printf(" -> ");
    }
    printf("\n");
}

void reverse(node **llHead)
{
    node *current = *llHead;
    node *link;
    while (current->link != NULL)
    {
        link = current->link;
        current->link = link->link;
        link->link = (*llHead);
        *llHead = link;
    }
}

/*
------
OUTPUT
------
Enter elements: 1 2 3 4 5
Original linked list: 1 -> 2 -> 3 -> 4 -> 5
Reversed linked list: 5 -> 4 -> 3 -> 2 -> 1
*/