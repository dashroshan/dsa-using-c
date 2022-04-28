/*
Using built-in C functions, write a program to generate random numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int min, max;
    printf("Enter minimum and maximum value: ");
    scanf("%d %d", &min, &max);
    srand(time(NULL));
    printf("Random number: %d", rand() % (max - min) + min);
}

/*
Enter minimum and maximum value: 1 100
Random number: 18
*/