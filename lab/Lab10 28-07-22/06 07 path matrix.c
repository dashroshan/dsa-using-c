// WAP to compute path matrix using both Floyd Warshall and Power of adjacency matrix algorithms

#include <stdio.h>
#include <stdlib.h>

int **input(int *);
void display(int **, int, char *);
int **copy(int **, int);
int **add(int **, int **, int);
int **multiply(int **, int **, int);
int **powerOfAdjMat(int **, int);
void floydWarshall(int **, int);

int main()
{
    int v, **g1 = input(&v), **g2 = copy(g1, v), **pOfAdjMat;
    pOfAdjMat = powerOfAdjMat(g1, v);
    display(pOfAdjMat, v, "\nReachability matrix using Power of adjacency matrix algorithm:\n");
    floydWarshall(g2, v);
    display(g2, v, "\nAll pairs shortest path matrix using Floyd Warshall algorithm:\n");
    return 0;
}

int **input(int *v)
{
    printf("Enter total vertices: ");
    scanf("%d", v);
    printf("Enter the adjacency matrix (0 for i to i, -1 for infinity):\n");
    int **matrix = (int **)malloc((*v) * sizeof(int *));
    for (int i = 0; i < *v; i++)
    {
        matrix[i] = (int *)malloc((*v) * sizeof(int));
        for (int j = 0; j < *v; j++)
            scanf("%d", &matrix[i][j]);
    }
    return matrix;
}

void display(int **g, int v, char *text)
{
    printf("%s", text);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%-3d ", g[i][j]);
        printf("\n");
    }
}

int **copy(int **g, int v)
{
    int **matrix = (int **)malloc((v) * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        matrix[i] = (int *)malloc((v) * sizeof(int));
        for (int j = 0; j < v; j++)
            matrix[i][j] = g[i][j];
    }
    return matrix;
}

int **add(int **m1, int **m2, int v)
{
    int **matrix = (int **)malloc((v) * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        matrix[i] = (int *)malloc((v) * sizeof(int));
        for (int j = 0; j < v; j++)
            matrix[i][j] = m1[i][j] + m2[i][j];
    }
    return matrix;
}

int **multiply(int **m1, int **m2, int v)
{
    int **matrix = (int **)malloc((v) * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        matrix[i] = (int *)malloc((v) * sizeof(int));
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < v; k++)
                matrix[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return matrix;
}

int **powerOfAdjMat(int **g, int v)
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            if (g[i][j] == -1)
                g[i][j] = 0;
            else if (g[i][j] != 0)
                g[i][j] = 1;
        }

    int ***m = (int ***)malloc((v) * sizeof(int **));
    m[0] = g;
    for (int i = 1; i < v; i++)
    {
        m[i] = multiply(m[i - 1], g, v);
        m[0] = add(m[i], m[0], v);
    }

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (m[0][i][j] != 0)
                m[0][i][j] = 1;
    return m[0];
}

void floydWarshall(int **g, int v)
{
    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
            {
                int oldPath = g[i][j];
                int newPath = g[i][k] + g[k][j];
                if (oldPath == -1 && (g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = -1;
                else if (oldPath == -1)
                    g[i][j] = newPath;
                else if ((g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = oldPath;
                else
                    g[i][j] = (newPath < oldPath) ? newPath : oldPath;
            }
}

/*
Enter total vertices: 4
Enter the adjacency matrix (0 for i to i, -1 for infinity):
0 3 -1 7
8 0 2 -1
5 -1 0 1
2 -1 -1 0

Reachability matrix using Power of adjacency matrix algorithm:
1   1   1   1
1   1   1   1
1   1   1   1
1   1   1   1

All pairs shortest path matrix using Floyd Warshall algorithm:
0   3   5   6
5   0   2   3
3   6   0   1
2   5   7   0
*/