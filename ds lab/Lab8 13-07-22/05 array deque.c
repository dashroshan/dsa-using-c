#include <stdio.h>
#define MAX 5

int deque_arr[MAX];
int l = -1;
int r = -1;

void insert_r()
{
    int added_item;
    if ((l == 0 && r == MAX - 1) || (l == r + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (l == -1)
    {
        l = 0;
        r = 0;
    }
    else if (r == MAX - 1)
        r = 0;
    else
        r = r + 1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[r] = added_item;
}

void insert_l()
{
    int added_item;
    if ((l == 0 && r == MAX - 1) || (l == r + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (l == -1)
    {
        l = 0;
        r = 0;
    }
    else if (l == 0)
        l = MAX - 1;
    else
        l = l - 1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[l] = added_item;
}

void delete_l()
{
    if (l == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque_arr[l]);
    if (l == r)
    {
        l = -1;
        r = -1;
    }
    else if (l == MAX - 1)
        l = 0;
    else
        l = l + 1;
}

void delete_r()
{
    if (l == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", deque_arr[r]);
    if (l == r)
    {
        l = -1;
        r = -1;
    }
    else if (r == 0)
        r = MAX - 1;
    else
        r = r - 1;
}

void display_queue()
{
    int front_pos = l, rear_pos = r;
    if (l == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void input_que()
{
    int choice;
    do
    {
        printf("1.Insert at r\n");
        printf("2.Delete from l\n");
        printf("3.Delete from r\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_r();
            break;
        case 2:
            delete_l();
            break;
        case 3:
            delete_r();
            break;
        case 4:
            display_queue();
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 5);
}

void output_que()
{
    int choice;
    do
    {
        printf("1.Insert at r\n");
        printf("2.Insert at l\n");
        printf("3.Delete from l\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_r();
            break;
        case 2:
            insert_l();
            break;
        case 3:
            delete_l();
            break;
        case 4:
            display_queue();
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 5);
}

main()
{
    int choice;
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input_que();
        break;
    case 2:
        output_que();
        break;
    default:
        printf("Wrong choice\n");
    }
}