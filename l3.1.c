#include <stdio.h>
#include <stdlib.h>

// WAP to perform transpose of a given sparse matrix in 3-tuple format.

// Sample Input:
// Enter sparse matrix in 3-tuple format
// 4   5   4
// 0   2   33
// 1   1   17
// 2   3   46
// 3   4   51

int **transpose(int **matrix, int nonZeros)
{
    int **transposeMatrix;
    transposeMatrix = (int **)malloc((nonZeros + 1) * sizeof(int *));

    for (int i = 0; i < nonZeros + 1; i++)
    {
        transposeMatrix[i] = (int *)malloc(nonZeros * sizeof(int));
    }

    transposeMatrix[0][0] = matrix[0][1];
    transposeMatrix[0][1] = matrix[0][0];
    transposeMatrix[0][2] = matrix[0][2];

    int row = 1;
    for (int i = 0; i < matrix[0][1]; i++)
    {
        for (int j = 1; j < nonZeros + 1; j++)
        {
            if (matrix[j][1] == i)
            {
                transposeMatrix[row][0] = matrix[j][1];
                transposeMatrix[row][1] = matrix[j][0];
                transposeMatrix[row][2] = matrix[j][2];
                row++;
            }
        }
    }

    return transposeMatrix;
}

int main()
{
    int rows, cols, nonZeros;

    printf("Enter the number of rows, number of cols and number of non-zeros in 3-tuple matrix: ");
    scanf("%d %d %d", &rows, &cols, &nonZeros);

    int **matrix;
    matrix = (int **)malloc((nonZeros + 1) * sizeof(int *));

    for (int i = 0; i < nonZeros + 1; i++)
    {
        matrix[i] = (int *)malloc(3 * sizeof(int));
    }

    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZeros;

    printf("Enter the elements of the 3 tuple matrix: \n");
    for (int i = 1; i < nonZeros + 1; i++)
    {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }

    int **transposeMatrix = transpose(matrix, nonZeros);
    printf("The transpose of the given matrix is: \n");
    for (int i = 0; i < nonZeros + 1; i++)
    {
        printf("%d %d %d\n", transposeMatrix[i][0], transposeMatrix[i][1], transposeMatrix[i][2]);
    }
}