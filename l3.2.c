#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int nonzero)
{
    printf("The matrix is: \n");
    for (int i = 0; i <= nonzero; i++)
    {
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void findSum(int **matrix1, int **matrix2, int nonzero1, int nonzero2)
{
    int **result;
    int i = 1, j = 1;

    int idxForResult = 1;
    result = (int **)malloc((nonzero1 + nonzero2 + 1) * sizeof(int *));
    for (int k = 0; k <= nonzero1 + nonzero2; k++)
    {
        result[k] = (int *)malloc(3 * sizeof(int));
    }

    int row1, col1, val1, row2, col2, val2;

    result[0][0] = matrix1[0][0];
    result[0][1] = matrix1[0][1];
    result[0][2] = 0;

    while (i <= nonzero1 && j <= nonzero2)
    {
        row1 = matrix1[i][0];
        col1 = matrix1[i][1];
        val1 = matrix1[i][2];
        row2 = matrix2[j][0];
        col2 = matrix2[j][1];
        val2 = matrix2[j][2];

        if (row1 == row2 && col1 == col2)
        {
            result[idxForResult][0] = row1;
            result[idxForResult][1] = col1;
            result[idxForResult][2] = val1 + val2;
            i++;
            j++;
        }
        else if (row1 < row2 || (row1 == row2 && col1 < col2))
        {
            result[idxForResult][0] = row1;
            result[idxForResult][1] = col1;
            result[idxForResult][2] = val1;
            i++;
        }
        else
        {
            result[idxForResult][0] = row2;
            result[idxForResult][1] = col2;
            result[idxForResult][2] = val2;
            j++;
        }
        idxForResult++;
    }

    // leftover elements from matrix1
    while (i <= nonzero1)
    {
        result[idxForResult][0] = matrix1[i][0];
        result[idxForResult][1] = matrix1[i][1];
        result[idxForResult][2] = matrix1[i][2];
        i++;
        idxForResult++;
    }

    // leftover elements from matrix2
    while (j <= nonzero2)
    {
        result[idxForResult][0] = matrix2[j][0];
        result[idxForResult][1] = matrix2[j][1];
        result[idxForResult][2] = matrix2[j][2];
        j++;
        idxForResult++;
    }

    // 1 2
    // 1 4 6 7 9 10

    result[0][2] = idxForResult - 1;
    result = realloc(result, (idxForResult) * sizeof(int *));
    printMatrix(result, result[0][2]);
}

int main()
{
    int **matrix1, **matrix2;
    int rows1, cols1, nonzero1, rows2, cols2, nonzero2;

    // Input 1
    printf("Enter the number of rows, number of cols and number of non-zeros in 3-tuple matrix 1: ");
    scanf("%d %d %d", &rows1, &cols1, &nonzero1);

    matrix1 = (int **)malloc((nonzero1 + 1) * sizeof(int *));
    for (int i = 0; i <= nonzero1; i++)
    {
        matrix1[i] = (int *)malloc(3 * sizeof(int));
    }

    matrix1[0][0] = rows1;
    matrix1[0][1] = cols1;
    matrix1[0][2] = nonzero1;

    printf("Enter the elements for 3-tuple matrix 1: ");
    for (int i = 1; i <= nonzero1; i++)
    {
        scanf("%d %d %d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    }

    // Input 2
    printf("Enter the number of rows, number of cols and number of non-zeros in 3-tuple matrix 2: ");
    scanf("%d %d %d", &rows2, &cols2, &nonzero2);

    matrix2 = (int **)malloc((nonzero2 + 1) * sizeof(int *));
    for (int i = 0; i <= nonzero2; i++)
    {
        matrix2[i] = (int *)malloc(3 * sizeof(int));
    }

    matrix2[0][0] = rows2;
    matrix2[0][1] = cols2;
    matrix2[0][2] = nonzero2;

    printf("Enter the elements for 3-tuple matrix 2: ");
    for (int i = 1; i <= nonzero2; i++)
    {
        scanf("%d %d %d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
    }

    if (rows1 == rows2 && cols1 == cols2)
    {
        findSum(matrix1, matrix2, nonzero1, nonzero2);
    }
    else
    {
        printf("Matrices cannot be added. They have different dimensions.\n");
    }
    return 0;
}
