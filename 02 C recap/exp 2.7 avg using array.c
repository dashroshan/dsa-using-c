/*
Using single-dimensional array, write a program to find the average of 10
numbers
*/

#include <stdio.h>
#define TOTAL 10
void main()
{
    int array[TOTAL];
    double sum = 0.0;
    printf("Enter %d numbers: ", TOTAL);
    for (int i = 0; i < TOTAL; i++)
    {
        scanf("%d", &array[i]);
        sum += array[i];
    }
    printf("Average: %0.2lf", sum / TOTAL);
}

/*
Enter 10 numbers: 0 1 2 3 4 5 6 7 8 9
Average: 4.50
*/