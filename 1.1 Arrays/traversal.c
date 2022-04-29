/*
Write a C program to traverse each element of an array and print its value on the console
*/

#include <stdio.h>

void traverse(int array[], int size);

void main()
{
    int array[] = {1, 2, 3, 4, 5}, size = sizeof(array) / sizeof(array[0]);
    printf("Array: ");
    traverse(array, size);
}

void traverse(int array[], int size)
{
    // Loop through the array elements and print them
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        // No comma after the last element
        if (i != size - 1)
            printf(", ");
    }
}

/*
Array: 1, 2, 3, 4, 5
*/