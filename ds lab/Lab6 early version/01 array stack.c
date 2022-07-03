#include <stdio.h>
#define MAX_SIZE 10

int push(int *stack, int *top, int element)
{
    if (*top >= MAX_SIZE - 1)
        return 0;
    *top += 1;
    stack[*top] = element;
    return 1;
}

int pop(int *stack, int *top)
{
    if (*top <= -1)
        return NULL;
    *top -= 1;
    return stack[*top + 1];
}

int peep(int *stack, int *top, int fromTop)
{
    if (fromTop > *top)
        return NULL;
    return stack[*top - fromTop];
}

int update(int *stack, int *top, int fromTop, int element)
{
    if (fromTop > *top)
        return NULL;
    int oldElement = stack[*top - fromTop];
    stack[*top - fromTop] = element;
    return oldElement;
}

int main()
{
    int stack[MAX_SIZE], top = -1, element, fromTop, result;
    char choice;
loop:
    printf("\na: Push\nb: Pop\nc: Peep\nd: Update\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter element to push: ");
        scanf("%d", &element);
        result = push(stack, &top, element);
        if (result)
            printf("%d pushed to stack\n", element);
        else
            printf("Push operation failed due to stack overflow\n");
        goto loop;
    case 'b':
        result = pop(stack, &top);
        if (result == NULL)
            printf("Pop operation failed due to stack underflow\n");
        else
            printf("%d popped from stack\n", result);
        goto loop;
    case 'c':
        printf("Enter index to peep from top: ");
        scanf("%d", &fromTop);
        result = peep(stack, &top, fromTop);
        if (result == NULL)
            printf("Peep operation failed due to insufficient elements\n");
        else
            printf("%d is at %d positions from the top\n", result, fromTop);
        goto loop;
    case 'd':
        printf("Enter new element and index to update from top: ");
        scanf("%d %d", &element, &fromTop);
        result = update(stack, &top, fromTop, element);
        if (result == NULL)
            printf("Update operation failed due to insufficient elements\n");
        else
            printf("%d at %d positions from top is updated with %d\n", result, fromTop, element);
        goto loop;
    default:
        goto loop;
    }
    return 0;
}