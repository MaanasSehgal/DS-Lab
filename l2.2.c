#include <stdio.h>

// 2.2 Write a program to perform the following operations on a given square matrix using functions:
// i.   Find the no.of nonzero elements
// ii.  Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal

void findOutput(int matrix[100][100], int n)
{
    int nonZeroElements = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZeroElements++;
            }
        }
    }
    printf("Number of non zero elements: %d\n", nonZeroElements);
    printf("Upper triangular matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    printf("Elements below main diagonal:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int matrix[100][100];
    int n;

    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    findOutput(matrix, n);
}