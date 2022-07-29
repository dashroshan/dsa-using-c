#include <stdio.h>

int *create(int *size);
void display(int *array, int size);
void selectionSort(int *array, int size);

void main()
{
    int size, *array = create(&size);
    selectionSort(array, size);
    display(array, size);
}

/*
Make [size] number of passes over the array starting from A[iteration] to
A[size-1]. Find the smallest element in each pass and swap it with A[iteration]
*/
void selectionSort(int *array, int size)
{
    int smallest, id, temp;
    for (int i = 0; i < size; i++)
    {
        smallest = array[i];
        id = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < smallest)
            {
                smallest = array[j];
                id = j;
            }
        }
        temp = array[i];
        array[i] = array[id];
        array[id] = temp;
    }
}

int *create(int *size)
{
    printf("Total elements: ");
    scanf("%d", size);
    int *array = (int *)malloc((*size) * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
    return array;
}

void display(int *array, int size)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}