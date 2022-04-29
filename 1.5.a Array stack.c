#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

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
        printf("%d popped from the stack\n", pop());
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
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack out of capacity\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("%d pushed to the stack\n", element);
}

int pop(void)
{
    if (top < 0)
    {
        printf("Empty stack\n");
        return;
    }
    top--;
    return stack[top + 1];
}

int size(void)
{
    return top + 1;
}

void display(void)
{
    if (top < 0)
    {
        printf("Empty stack\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
        if (i != top)
            printf(", ");
    }
    printf("\n");
}