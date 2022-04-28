/*
Write a program to compute the sum of elements of an integer array
*/

#include <stdio.h>
#define TOTAL 10
void main()
{
    int array[TOTAL];
    int sum = 0.0;
    printf("Enter %d numbers: ", TOTAL);
    for (int i = 0; i < TOTAL; i++)
    {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    printf("Sum of elements: %d", sum);
}

/*
Enter 10 numbers: 0 1 2 3 4 5 6 7 8 9
Sum of elements: 45
*/