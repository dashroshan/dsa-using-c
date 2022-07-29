#include <stdio.h>

int *create(int *size);
void display(int *array, int size);
void bubbleSort(int *array, int size);

void main()
{
    int size, *array = create(&size);
    bubbleSort(array, size);
    display(array, size);
}

/*
Make [size] number of passes over the array from A[1] to A[size-1]. If previous
element is greater than the current element, swap them.
*/
void bubbleSort(int *array, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (array[j - 1] > array[j])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
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