#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous, *next;
};

struct node *head = NULL, *tail = NULL;

struct node *createNode(int data)
{
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = nnode->previous = NULL;
    return (nnode);
}

void createSentinels()
{
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->previous = head;
}

void enqueueAtFront(int data)
{
    struct node *nnode, *temp;
    nnode = createNode(data);
    temp = head->next;
    head->next = nnode;
    nnode->previous = head;
    nnode->next = temp;
    temp->previous = nnode;
}

void enqueueAtRear(int data)
{
    struct node *nnode, *temp;
    nnode = createNode(data);
    temp = tail->previous;
    tail->previous = nnode;
    nnode->next = tail;
    nnode->previous = temp;
    temp->next = nnode;
}

void dequeueAtFront()
{
    struct node *temp;
    if (head->next == tail)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = head->next;
        head->next = temp->next;
        temp->next->previous = head;
        free(temp);
    }
    return;
}

void dequeueAtRear()
{
    struct node *temp;
    if (tail->previous == head)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = tail->previous;
        tail->previous = temp->previous;
        temp->previous->next = tail;
        free(temp);
    }
    return;
}

void display()
{
    struct node *temp;

    if (head->next == tail)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head->next;
    while (temp != tail)
    {
        printf("%-3d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data, ch;
    createSentinels();
    while (1)
    {
        printf("1. Enqueue at front\n2. Enqueue at rear\n");
        printf("3. Dequeue at front\n4. Dequeue at rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data to insert:");
            scanf("%\nd", &data);
            enqueueAtFront(data);
            break;

        case 2:
            printf("Enter your data to insert:");
            scanf("\n%d", &data);
            enqueueAtRear(data);
            break;

        case 3:
            dequeueAtFront();
            break;

        case 4:
            dequeueAtRear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Plsease enter correct option\n");
            break;
        }
    }
    return 0;
}