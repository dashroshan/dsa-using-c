/*
Write a C program that uses any one of the special operators of C
*/

#include <stdio.h>
void main()
{
    int array[] = {1, 2, 3, 4, 5};
    printf("Size of array found using sizeof operator: %d", sizeof(array) / sizeof(array[0]));
}

/*
Size of array found using sizeof operator: 5
*/