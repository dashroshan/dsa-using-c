/*
Write a C program to read three integers and then display their sum
*/

#include <stdio.h>
void main()
{
    int n1, n2, n3;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("Sum: %d", n1 + n2 + n3);
}

/*
Enter 3 numbers: 1 2 3
Sum: 6
*/