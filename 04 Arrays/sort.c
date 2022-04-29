/*
Implement bubble sorting technique to sort an array
*/

#include <stdio.h>

void sort(int array[], int size);

void main()
{
    int array[] = {5, 2, 1, 4, 3}, size = sizeof(array) / sizeof(array[0]);
    sort(array, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void sort(int array[], int size)
{
    int temp;
    // Loop through the array size number of times
    for (int i = 0; i < size; i++)
    {
        // Loop through the array elements starting from the element at position
        // 1. If element before is larger than current element, swap them.
        for (int j = 1; j < size; j++)
        {
            if (array[j - 1] > array[j])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

/*
Sorted array: 1 2 3 4 5
*/