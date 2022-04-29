#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int num;
    struct nodeStruct *next;
} node;

node *create(void);
void display(node *head);
int search(node *head, int num);
int length(node *head);
void insert(node **head, int num, int index);
void delete (node **head, int index);

void main()
{
    node *llHead = create();
    int choice, toSearch, toInsert, index;
loop:
    // Start of the menu loop
    printf("\n1: Length\n2: Display\n3: Search\n4: Insert\n5: Delete\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1: // Show length of the linked list
        printf("Length of the linked list: %d\n", length(llHead));
        goto loop;

    case 2: // Display the linked list
        display(llHead);
        goto loop;

    case 3: // Search the index of an element
        printf("Enter element to search: ");
        scanf("%d", &toSearch);
        index = search(llHead, toSearch);
        if (index == -1)
            printf("%d not found in the linked list\n", toSearch);
        else
            printf("%d found at index %d\n", toSearch, index);
        goto loop;

    case 4: // Insert a new element at an index
        printf("Enter element and index where it is to be inserted: ");
        scanf("%d %d", &toInsert, &index);
        insert(&llHead, toInsert, index);
        printf("%d inserted at index %d\n", toInsert, index);
        goto loop;

    case 5: // Delete element at an index
        printf("Enter element index to delete: ");
        scanf("%d", &index);
        delete (&llHead, index);
        printf("Element deleted\n");
        goto loop;
    }
}

node *create(void)
{
    int num;
    node *head = (node *)malloc(sizeof(node)), *list = head;
    printf("Enter elements (-999 to stop): ");
    scanf("%d", &list->num);
    while (1)
    {
        scanf("%d", &num);
        if (num == -999)
        {
            list->next = head;
            break;
        }
        list->next = (node *)malloc(sizeof(node));
        list = list->next;
        list->num = num;
    }
    return head;
}

void display(node *head)
{
    printf("Linked list: ");
    node *list = head;
    while (1)
    {
        printf("%d", list->num);
        if (list->next == head)
            break;
        else
            list = list->next;
        printf(", ");
    }
    printf("\n");
}

int search(node *head, int num)
{
    node *list = head;
    int index = 0;
    while (1)
    {
        if (list->num == num)
            return index;
        index++;
        if (list->next == head)
            break;
        else
            list = list->next;
    }
    return -1;
}

int length(node *head)
{
    node *list = head;
    int index = 0;
    while (1)
    {
        index++;
        if (list->next == head)
            break;
        else
            list = list->next;
    }
    return index;
}

void insert(node **head, int num, int index)
{
    node *list = *head;
    int currentIndex = 0;
    if (index == 0)
    {
        node *first = (node *)malloc(sizeof(node));
        first->num = num;
        first->next = *head;
        while (1)
        {
            if (list->next == *head)
            {
                list->next = first;
                break;
            }
            else
                list = list->next;
        }
        *head = first;
        return;
    }
    while (1)
    {
        if (currentIndex == index - 1)
        {
            node *toInsert = (node *)malloc(sizeof(node));
            toInsert->num = num;
            toInsert->next = list->next;
            list->next = toInsert;
            break;
        }
        if (list->next == *head)
            return;
        list = list->next;
        currentIndex++;
    }
}

void delete (node **head, int index)
{
    node *list = *head;
    int currentIndex = 0;
    if (index == 0)
    {
        while (1)
        {
            if (list->next == *head)
            {
                list->next = (*head)->next;
                break;
            }
            else
                list = list->next;
        }
        *head = (*head)->next;
        return;
    }
    while (1)
    {
        if (currentIndex == index - 1)
        {
            node *nodeAfterDeletedNode = list->next->next;
            free(list->next);
            list->next = nodeAfterDeletedNode;
        }
        if (list->next == *head)
        {
            list->next = (*head)->next;
            return;
        }
        list = list->next;
        currentIndex++;
    }
}