#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int element);
int delete (void);
int size(void);
void display(void);

void main()
{
    int choice, element;
loop:
    printf("\n1: Insert\n2: Delete\n3: Display\n\nEnter your choice: ");
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
        printf("%d deleted from the queue\n", delete ());
        goto loop;
    case 3:
        display();
        goto loop;
    default:
        goto loop;
    }
}

void insert(int element)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1)
    {
        printf("Queue out of capacity\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
        rear = 0;
    else
        rear = rear + 1;
    queue[rear] = element;
    printf("%d inserted to the queue\n", element);
}

int delete (void)
{
    int i;
    if (front == -1)
    {
        printf("Empty queue\n");
    }
    i = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return (i);
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
        return (i);
    }
    else
    {
        front = front + 1;
        return (i);
    }
}

void display(void)
{
    int i;
    if (front == -1)
    {
        printf("Empty queue\n");
        return;
    }
    printf("Queue: ");
    i = front;
    while (i != rear)
    {
        printf("%d <- ", queue[i]); /*Printing queue elements*/
        if (i == MAX_SIZE - 1)
            i = 0;
        else
            i = i + 1;
    }
    printf("%d\n", queue[i]);
}