/*
Using multi-dimensional array, write a program to realize a 3 x 3 matrix.
*/

#include <stdio.h>
#define M 3
#define N 3
void main()
{
    int array[M][N];
    printf("Enter a %dx%d matrix:\n", M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    }
    printf("\nEntered matrix:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%-2d", array[i][j]);
        printf("\n");
    }
}

/*
Enter a 3x3 matrix:
1 2 3
4 5 6
7 8 9

Entered matrix:
1 2 3
4 5 6
7 8 9
*/