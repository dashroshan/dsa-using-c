// Implement polynomial addition using linked list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodeStruct
{
    int coeff;
    int pow;
    struct nodeStruct *link;
} node;

void input(node **);
void display(node *);
void add(node *, node *, node **);
void insertAtEnd(node **, int, int);

int main()
{
    node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;
    printf("Enter polynomials as '2x3 5x1 -4x0' for 2x^3 + 5x^1 - 4x^0\nThe terms should be in the decreasing power of x\n\n");
    input(&poly1);
    input(&poly2);
    add(poly1, poly2, &polySum);
    printf("\nSum of both polynomials: ");
    display(polySum);
    return 0;
}

void input(node **poly)
{
    int coeff, pow;
    char last;
    printf("Enter polynomial: ");
    do
    {
        scanf("%d%*c%d%c", &coeff, &pow, &last);
        insertAtEnd(poly, coeff, pow);
    } while (last != '\n');
}

void insertAtEnd(node **first, int coeff, int pow)
{
    node *new = (node *)malloc(sizeof(node)), *llptr = *first;
    new->coeff = coeff;
    new->pow = pow;
    new->link = NULL;
    if (*first == NULL)
    {
        *first = new;
        return;
    }
    while (llptr->link != NULL)
        llptr = llptr->link;
    llptr->link = new;
}

void add(node *poly1, node *poly2, node **polySum)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            insertAtEnd(polySum, poly1->coeff, poly1->pow);
            poly1 = poly1->link;
        }
        else if (poly2->pow > poly1->pow)
        {
            insertAtEnd(polySum, poly2->coeff, poly2->pow);
            poly2 = poly2->link;
        }
        else
        {
            insertAtEnd(polySum, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    if (poly1 == NULL && poly2 == NULL)
        return;
    node *polyLeft = (poly1 != NULL) ? poly1 : poly2;
    while (polyLeft != NULL)
    {
        insertAtEnd(polySum, polyLeft->coeff, polyLeft->pow);
        polyLeft = polyLeft->link;
    }
}

void display(node *first)
{
    node *llptr = first;
    while (llptr != NULL)
    {
        printf("%c %dx^%d ", (llptr->coeff < 0) ? '-' : '+', abs(llptr->coeff), llptr->pow);
        llptr = llptr->link;
    }
}

/*
Enter polynomials as '2x3 5x1 -4x0' for 2x^3 + 5x^1 - 4x^0
The terms should be in the decreasing power of x

Enter polynomial: 2x3 -4x2
Enter polynomial: 4x5 -1x3 +9x2 -3x0

Sum of both polynomials: + 4x^5 + 1x^3 + 5x^2 - 3x^0
*/