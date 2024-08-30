#include <stdio.h>

void convertToNormalMatrix(int sparseMatrix[][3], int rows)
{
    int maxRow = sparseMatrix[0][0];
    int maxCol = sparseMatrix[0][1];

    int matrix[maxRow][maxCol];
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i < rows; i++)
    {
        int row = sparseMatrix[i][0];
        int col = sparseMatrix[i][1];
        int val = sparseMatrix[i][2];
        matrix[row][col] = val;
    }

    printf("Normal matrix:\n");
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows;

    printf("Enter num of non zero elements: ");
    scanf("%d", &rows);

    int sparseMatrix[rows + 1][3];

    printf("Enter the number of rows and columns in the original matrix: ");
    scanf("%d %d", &sparseMatrix[0][0], &sparseMatrix[0][1]);

    sparseMatrix[0][2] = rows;

    printf("Enter the non-zero elements of the sparse matrix (row, col, value):\n");
    for (int i = 1; i <= rows; i++)
    {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    convertToNormalMatrix(sparseMatrix, rows + 1);
    return 0;
}
