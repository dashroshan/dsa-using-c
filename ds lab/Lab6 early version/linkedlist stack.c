#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    char info;
    struct nodeStruct *link;
} node;

void push(node **top, char info)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = info;
    new->link = *top;
    *top = new;
}

int pop(node **top)
{
    if (*top == NULL)
        return NULL;
    int popped = (*top)->info;
    node *toFree = *top;
    *top = (*top)->link;
    free(toFree);
    return popped;
}

int main()
{
    node *stack = NULL;
    int element, result;
    char choice;
loop:
    printf("\na: Push\nb: Pop\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter element to push: ");
        scanf("%d", &element);
        push(&stack, element);
        printf("%d pushed to stack\n", element);
        goto loop;
    case 'b':
        result = pop(&stack);
        if (result == NULL)
            printf("Pop operation failed due to stack underflow\n");
        else
            printf("%d popped from stack\n", result);
        goto loop;
    default:
        goto loop;
    }
    return 0;
}