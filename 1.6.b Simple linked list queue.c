#include <stdio.h>
#define MAX_SIZE 100

typedef struct nodeStruct
{
    int num;
    struct nodeStruct *next;
} node;

node *queue = NULL;

void insert(int element);
int delete (void);
int size(void);
void display(void);

void main()
{
    int choice, element;
loop:
    printf("\n1: Insert\n2: Delete\n3: Size\n4: Display\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Enter element to insert: ");
        scanf("%d", &element);
        insert(element);
        goto loop;
    case 2:
        element = delete ();
        if (element != NULL)
            printf("%d deleted from the queue\n", element);
        goto loop;
    case 3:
        printf("Queue has %d elements\n", size());
        goto loop;
    case 4:
        display();
        goto loop;
    default:
        goto loop;
    }
}

void insert(int element)
{
    node *temp = queue, *newNode = (node *)malloc(sizeof(node));
    newNode->num = element;
    newNode->next = NULL;
    while (1)
    {
        if (temp == NULL)
        {
            queue = newNode;
            break;
        }
        if (temp->next == NULL)
        {
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    printf("%d inserted to the queue\n", element);
}

int delete (void)
{
    if (queue == NULL)
    {
        printf("Empty queue\n");
        return NULL;
    }
    node *temp = queue;
    queue = queue->next;
    int num = temp->num;
    free(temp);
    return num;
}

int size(void)
{
    node *temp = queue;
    int count = 0;
    while (1)
    {
        if (temp == NULL)
            break;
        count++;
        temp = temp->next;
    }
    return count;
}

void display(void)
{
    if (queue == NULL)
    {
        printf("Empty queue\n");
        return;
    }
    printf("queue: ");
    node *temp = queue;
    while (1)
    {
        if (temp == NULL)
            break;
        printf("%d", temp->num);
        temp = temp->next;
        if (temp != NULL)
            printf(" <- ");
    }
    printf("\n");
}