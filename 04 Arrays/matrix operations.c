#include <stdio.h>
#include <stdlib.h>

int **input(int *row, int *column);
void display(int **matrix, int row, int column);
int **add(int **m1, int **m2, int row, int column);
int **subtract(int **m1, int **m2, int row, int column);
int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2);
int **transpose(int **m, int row, int column);

void main()
{
    int r1, c1, **m1 = input(&r1, &c1);
    int r2, c2, **m2 = input(&r2, &c2);

    printf("\nSUM\n");
    int **mSum = add(m1, m2, r1, c1);
    display(mSum, r1, c1);

    printf("\nDIFFERENCE\n");
    int **mDif = subtract(m1, m2, r1, c1);
    display(mDif, r1, c1);

    printf("\nPRODUCT\n");
    int **mPro = multiply(m1, m2, r1, c1, r2, c2);
    display(mPro, r1, c2);

    printf("\nTRANSPOSE of M1\n");
    int **mTra = transpose(m1, r1, c1);
    display(mTra, r1, c1);
}

int **input(int *row, int *column)
{
    printf("Enter size of matrix as: row column: ");
    scanf("%d %d", row, column);
    printf("Enter a %dx%d matrix:\n", *row, *column);

    // Pointer to row number of integer pointers
    int **matrix = (int **)malloc((*row) * sizeof(int *));
    for (int i = 0; i < *row; i++)
    {
        // Create an array of column number of integers at a row pointer
        matrix[i] = (int *)malloc((*column) * sizeof(int));
        for (int j = 0; j < *column; j++)
            scanf("%d", &matrix[i][j]);
    }
    return matrix;
}

void display(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%-3d", matrix[i][j]);
        printf("\n");
    }
}

int **add(int **m1, int **m2, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        for (int j = 0; j < column; j++)
            // Add elements at corresponding locations into the new matrix
            matrix[i][j] = m1[i][j] + m2[i][j];
    }
    return matrix;
}

int **subtract(int **m1, int **m2, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        for (int j = 0; j < column; j++)
            // Subtract elements at corresponding locations into the new matrix
            matrix[i][j] = m1[i][j] - m2[i][j];
    }
    return matrix;
}

int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2)
{
    // Check if the 2 matrices can be multiplied
    if (c1 != r2)
        return;
    int **matrix = (int **)malloc((r1) * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        matrix[i] = (int *)malloc((c2) * sizeof(int));
        for (int j = 0; j < c2; j++)
        {
            matrix[i][j] = 0;
            // Aij = Sum of Bik*Ckj for k=0 to columns of B (or rows of C)
            for (int k = 0; k < c1; k++)
                matrix[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return matrix;
}

int **transpose(int **m, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        // Aij = Bji for getting the transpose
        for (int j = 0; j < column; j++)
            matrix[i][j] = m[j][i];
    }
    return matrix;
}

/*
Enter size of matrix as: row column: 2 2
Enter a 2x2 matrix:
5 6
7 8
Enter size of matrix as: row column: 2 2
Enter a 2x2 matrix:
1 2
3 4

SUM
6  8
10 12

DIFFERENCE
4  4
4  4

PRODUCT
23 34
31 46

TRANSPOSE of M1
5  7
6  8
*/