#include <stdio.h>

// 2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.

// Sample Input:

// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix:
// 0  0  33  0
// 0  0  17  0
// 0  0  0   0
// 0  46 0   0
// 0  0  0  51
int main()
{
    int rows, cols;
    int matrix[100][100];
    printf("Enter the size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparseMatrix[100][3];
    int p = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[p][0] = i;
                sparseMatrix[p][1] = j;
                sparseMatrix[p][2] = matrix[i][j];
                p++;
            }
        }
    }

    printf("Sparse matrix: \n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}