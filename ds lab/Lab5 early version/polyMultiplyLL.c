// Implement polynomial multiplication using linked list

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
int lowestPow(node *);
void display(node *first);
void insertAtEnd(node **, int, int);
void multiply(node *, node *, node **);
void addToCoeffAtIndex(node **, int, int);

int main()
{
    node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;
    printf("Enter polynomials as '2x3 5x1 -4x0' for 2x^3 + 5x^1 - 4x^0\nThe terms should be in the decreasing power of x\n\n");
    input(&poly1);
    input(&poly2);
    multiply(poly1, poly2, &polySum);
    printf("\nProduct of both polynomials: ");
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

int lowestPow(node *poly)
{
    int pow;
    while (poly != NULL)
    {
        pow = poly->pow;
        poly = poly->link;
    }
    return pow;
}

void addToCoeffAtIndex(node **first, int value, int index)
{
    int curIndex = 0;
    node *ptr = *first;
    while (curIndex != index)
    {
        ptr = ptr->link;
        curIndex++;
    }
    ptr->coeff = ptr->coeff + value;
}

void multiply(node *poly1, node *poly2, node **polySum)
{
    int highestPow = poly1->pow + poly2->pow, lp1 = lowestPow(poly1), lp2 = lowestPow(poly2);
    for (int i = highestPow; i >= lp1 + lp2; i--)
        insertAtEnd(polySum, 0, i);
    while (poly1 != NULL)
    {
        node *p2 = poly2;
        while (p2 != NULL)
        {
            addToCoeffAtIndex(polySum, poly1->coeff * p2->coeff, highestPow - poly1->pow - p2->pow);
            p2 = p2->link;
        }
        poly1 = poly1->link;
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

Enter polynomial: 2x2 1x1
Enter polynomial: 3x3 -4x2 5x1

Product of both polynomials: + 6x^5 - 5x^4 + 6x^3 + 5x^2
*/