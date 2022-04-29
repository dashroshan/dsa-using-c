/*
Write a C program to perform array deletion
*/

#include <stdio.h>

void delete (int array[], int *size, int index)
{
    // Return if we try to delete an element beyond the defined array size
    if (index >= *size)
        return;

    // Loop from the index which we want to delete to the end of the array.
    // Continue moving the next element to the element at current position.
    for (int i = index; i < *size - 1; i++)
        array[i] = array[i + 1];

    // Reduce size by 1
    (*size)--;
}

void main()
{
    int array[] = {1, 2, 3, 4, 5}, size = 5, index = 2;
    printf("%d at index %d deleted: ", array[index], index);
    delete (array, &size, index);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

/*
3 at index 2 deleted: 1 2 4 5
*/