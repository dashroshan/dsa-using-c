/*
Write a C program to perform linear search on an array
*/

#include <stdio.h>

int search(int array[], int size, int element);

void main()
{
    int array[] = {1, 2, 3, 4, 5}, size = sizeof(array) / sizeof(array[0]), element = 4, position;
    position = search(array, size, element);
    if (position != -1)
        printf("%d found at index %d", element, position);
    else
        printf("%d not found in the given array", element);
}

int search(int array[], int size, int element)
{
    // Loop through all array elements, if the current element is the same as
    // the element we are searching for, return its index
    for (int i = 0; i < size; i++)
        if (array[i] == element)
            return i;

    // If we reach here it means the element was not found in the array, so we
    // return -1
    return -1;
}

/*
4 found at index 3
*/