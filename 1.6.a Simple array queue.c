#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;

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
        printf("%d deleted from the queue\n", delete ());
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
    if (front >= MAX_SIZE - 1)
    {
        printf("Queue out of capacity\n");
        return;
    }
    front++;
    queue[front] = element;
    printf("%d inserted to the queue\n", element);
}

int delete (void)
{
    if (front < 0)
    {
        printf("Empty queue\n");
        return;
    }
    int temp = queue[0];
    for (int i = 0; i < front; i++)
    {
        queue[i] = queue[i + 1];
    }
    front--;
    return temp;
}

int size(void)
{
    return front + 1;
}

void display(void)
{
    if (front < 0)
    {
        printf("Empty queue\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= front; i++)
    {
        printf("%d", queue[i]);
        if (i != front)
            printf(" <- ");
    }
    printf("\n");
}