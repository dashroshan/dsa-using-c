// WAP to implement selection sort, quick sort, merge sort, and bubble sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *s);
int *copy(int *a, int s);
void swap(int *e1, int *e2);
void display(int *a, int s, char *text);
void selectionSort(int *array, int size);
void quickSort(int array[], int low, int high);
void mergeSort(int array[], int low, int high);
void bubbleSort(int *array, int size);

int main()
{
    int s, *aOrg = input(&s), *a;

    a = copy(aOrg, s);
    display(a, s, "Before sorting: ");
    selectionSort(a, s);
    display(a, s, "Selection sort: ");

    a = copy(aOrg, s);
    display(a, s, "\nBefore sorting: ");
    quickSort(a, 0, s - 1);
    display(a, s, "Quick sort    : ");

    a = copy(aOrg, s);
    display(a, s, "\nBefore sorting: ");
    mergeSort(a, 0, s - 1);
    display(a, s, "Merge sort    : ");

    a = copy(aOrg, s);
    display(a, s, "\nBefore sorting: ");
    bubbleSort(a, s);
    display(a, s, "Bubble sort   : ");
    return 0;
}

int *copy(int *a, int s)
{
    int *aNew = (int *)malloc(sizeof(int) * s);
    for (int i = 0; i < s; i++)
        aNew[i] = a[i];
    return aNew;
}

int *input(int *s)
{
    printf("Input array size: ");
    scanf("%d", s);
    int *a = (int *)malloc(sizeof(int) * (*s)), i;
    printf("Enter array elements: ");
    for (i = 0; i < *s; i++)
        scanf("%d", &a[i]);
    return a;
}

void display(int *a, int s, char *text)
{
    printf("\n%s", text);
    for (int i = 0; i < s; i++)
        printf("%d ", a[i]);
}

void swap(int *e1, int *e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

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

void quickSort(int array[], int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high, pivot = array[low], temp;
    while (i < j)
    {
        while ((array[i] <= pivot) && i <= high)
            i++;
        while ((array[j] > pivot) && j >= low)
            j--;
        if (i < j)
            swap(&array[i], &array[j]);
    }
    swap(&array[j], &array[low]);
    quickSort(array, low, j - 1);
    quickSort(array, j + 1, high);
}

void mergeSort(int array[], int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    int ls = mid - low + 1, rs = high - mid, left[ls], right[rs];
    for (int i = 0; i < ls; i++)
        left[i] = array[low + i];
    for (int i = 0; i < rs; i++)
        right[i] = array[mid + i + 1];

    int li = 0, ri = 0, ai = low;
    while (li < ls && ri < rs)
    {
        if (left[li] <= right[ri])
        {
            array[ai] = left[li];
            li++;
        }
        else
        {
            array[ai] = right[ri];
            ri++;
        }
        ai++;
    }

    while (li < ls)
    {
        array[ai] = left[li];
        li++;
        ai++;
    }

    while (ri < rs)
    {
        array[ai] = right[ri];
        ri++;
        ai++;
    }
}

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
}

/*
Input array size: 5
Enter array elements: 4 1 5 2 3

Before sorting: 4 1 5 2 3
Selection sort: 1 2 3 4 5

Before sorting: 4 1 5 2 3
Quick sort    : 1 2 3 4 5

Before sorting: 4 1 5 2 3
Merge sort    : 1 2 3 4 5

Before sorting: 4 1 5 2 3
Bubble sort   : 1 2 3 4 5
*/