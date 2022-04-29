#include <stdio.h>
#define MAX_SIZE 100

typedef struct nodeStruct
{
    int num;
    struct nodeStruct *next;
} node;

node *stack = NULL;

void push(int element);
int pop(void);
int size(void);
void display(void);

void main()
{
    int choice, element;
loop:
    printf("\n1: Push\n2: Pop\n3: Size\n4: Display\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Enter element to push: ");
        scanf("%d", &element);
        push(element);
        goto loop;
    case 2:
        element = pop();
        if (element != NULL)
            printf("%d popped from the stack\n", element);
        goto loop;
    case 3:
        printf("Stack has %d elements\n", size());
        goto loop;
    case 4:
        display();
        goto loop;
    default:
        goto loop;
    }
}

void push(int element)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->num = element;
    newNode->next = stack;
    stack = newNode;
    printf("%d pushed to the stack\n", element);
}

int pop(void)
{
    if (stack == NULL)
    {
        printf("Empty stack\n");
        return NULL;
    }
    node *temp = stack;
    stack = stack->next;
    int num = temp->num;
    free(temp);
    return num;
}

int size(void)
{
    node *temp = stack;
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
    if (stack == NULL)
    {
        printf("Empty stack\n");
        return;
    }
    printf("Stack: ");
    node *temp = stack;
    while (1)
    {
        if (temp == NULL)
            break;
        printf("%d", temp->num);
        temp = temp->next;
        if (temp != NULL)
            printf(", ");
    }
    printf("\n");
}