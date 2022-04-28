/*
Create a five-element array and print the address of each of its elements.
*/

#include <stdio.h>
#define TOTAL 5
void main()
{
    int array[TOTAL];
    printf("Enter %d numbers: ", TOTAL);
    for (int i = 0; i < TOTAL; i++)
        scanf("%d", &array[i]);
    printf("\n%-10s%-10s\n", "ADDRESS", "ELEMENT");
    for (int i = 0; i < TOTAL; i++)
        printf("%-10u%-10d\n", &array[i], array[i]);
}

/*
Enter 5 numbers: 1 2 3 4 5

ADDRESS   ELEMENT
6422016   1
6422020   2
6422024   3
6422028   4
6422032   5
*/