#include <stdio.h>

int *create(int *size);
void display(int *array, int size);
void insertionSort(int *array, int size);

void main()
{
    int size, *array = create(&size);
    insertionSort(array, size);
    display(array, size);
}

/*
Iterate from A[1] to A[size-1]. Move previous elements greater than A[iteration]
1 postion forward. Put A[iteration] in the vacant space created.
*/
void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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