/*
Write a C program to perform array insertion
*/

#include <stdio.h>

void insert(int array[], int *size, int element, int position);

void main()
{
    int array[10] = {1, 2, 3, 4, 5}, size = 5, element = 10, position = 2;
    insert(array, &size, element, position);
    printf("%d inserted at %d position: ", element, position);
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void insert(int array[], int *size, int element, int position)
{
    // Return if we try to insert beyond the defined array size
    if (position >= *size)
        return;

    // Loop from last element to the element at the position where we want to
    // insert. Continue moving the elements to the next index. When at the
    // position where we want to insert, add the element.
    for (int i = *size - 1; i >= position; i--)
    {
        array[i + 1] = array[i];
        if (i == position)
            array[i] = element;
    }

    // Increase size by 1
    (*size)++;
}

/*
10 inserted at 2 position: 1 2 10 3 4 5
*/