#include <stdio.h>
#include <stdlib.h>

int *input(int *degree);
int isZero(int *polynomial, int degree);
void display(int *polynomial, int degree);
int *add(int *p1, int *p2, int d1, int d2, int *degree);
int coefficient(int *polynomial, int degree, int xPower);
void removeTerm(int *polynomial, int *degree, int xPower);
int *product(int *p1, int *p2, int d1, int d2, int *degree);
int *singleProduct(int *p, int d, int coefficient, int xPower, int *degree);

void main()
{
    int choice, degree, *polynomial = input(&degree);
    int d1, *p1, d2, *p2, xPower, coeff;
loop:
    printf("\n1: Display\n2: Add\n3: Is zero\n4: Coefficient\n5: Single multiplication\n6: Multiplication\n7: Removed term\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        display(polynomial, degree);
        goto loop;
    case 2:
        p1 = input(&d1);
        p2 = add(polynomial, p1, degree, d1, &d2);
        printf("\n  ");
        display(polynomial, degree);
        printf("+ ");
        display(p1, d1);
        printf("\n= ");
        display(p2, d2);
        free(p1);
        free(p2);
        goto loop;
    case 3:
        if (isZero(polynomial, degree))
            printf("Its a zero polynomial\n");
        else
            printf("Its not a zero polynomial\n");
        goto loop;
    case 4:
        printf("Enter power of x: ");
        scanf("%d", &xPower);
        coeff = coefficient(polynomial, degree, xPower);
        printf("Coefficient of x^%d = %d\n", xPower, coeff);
        goto loop;
    case 5:
        printf("Enter term to multiply as ax^b: ");
        scanf("%dx^%d", &coeff, &xPower);
        p1 = singleProduct(polynomial, degree, coeff, xPower, &d1);
        printf("\n  ");
        display(polynomial, degree);
        printf("x %dx^%d\n= ", coeff, xPower);
        display(p1, d1);
        free(p1);
        goto loop;
    case 6:
        p1 = input(&d1);
        p2 = product(polynomial, p1, degree, d1, &d2);
        printf("\n   ");
        display(polynomial, degree);
        printf("x  ");
        display(p1, d1);
        printf("=  ");
        display(p2, d2);
        free(p1);
        free(p2);
        goto loop;
    case 7:
        printf("Enter power of x: ");
        scanf("%d", &xPower);
        removeTerm(polynomial, &degree, xPower);
        printf("x^%d term removed\n", xPower);
        goto loop;
    default:
        goto loop;
    }
}

int *input(int *degree)
{
    printf("Enter degree of the polynomial: ");
    scanf("%d", degree);
    int *array = (int *)malloc((*degree + 1) * sizeof(int));
    printf("Enter the coefficients (ex: 4 + 2x^2 as 4 0 2): ");
    for (int i = 0; i <= *degree; i++)
        scanf("%d", &array[i]);
    return array;
}

void display(int *polynomial, int degree)
{
    printf("Polynomial: ");
    for (int i = 0; i <= degree; i++)
    {
        if (polynomial[i] != 0)
        {
            printf("%d", polynomial[i]);
            if (i != 0)
                printf("x^%d", i);
            if (i != degree)
                printf(" + ");
        }
    }
    printf("\n");
}

int *add(int *p1, int *p2, int d1, int d2, int *degree)
{
    *degree = (d1 >= d2) ? d1 : d2;
    int *array = (int *)malloc((*degree + 1) * sizeof(int));
    for (int i = 0; i <= *degree; i++)
        array[i] = ((i <= d1) ? p1[i] : 0) + ((i <= d2) ? p2[i] : 0);
    return array;
}

int isZero(int *polynomial, int degree)
{
    for (int i = 0; i <= degree; i++)
        if (polynomial[i] != 0)
            return 0;
    return 1;
}

int coefficient(int *polynomial, int degree, int xPower)
{
    if (xPower > degree)
        return 0;
    else
        return polynomial[xPower];
}

int *singleProduct(int *p, int d, int coefficient, int xPower, int *degree)
{
    *degree = d + xPower;
    int *polynomial = (int *)malloc((*degree) * sizeof(int));
    for (int i = d; i >= 0; i--)
        polynomial[i + xPower] = p[i] * coefficient;
    for (int i = 0; i < xPower; i++)
        polynomial[i] = 0;
    return polynomial;
}

int *product(int *p1, int *p2, int d1, int d2, int *degree)
{
    *degree = d1 + d2;
    int *polynomial = (int *)calloc(*degree, sizeof(int));
    for (int i = 0; i <= d2; i++)
        for (int j = 0; j <= d1; j++)
            polynomial[i + j] += p2[i] * p1[j];
    return polynomial;
}

void removeTerm(int *polynomial, int *degree, int xPower)
{
    if (*degree == xPower)
        (*degree)--;
    if (*degree >= xPower)
        polynomial[xPower] = 0;
}