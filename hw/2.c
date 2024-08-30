#include <stdio.h>
#include <stdlib.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int swapFlag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapFlag = 1;
            }
        }
        if (swapFlag == 0)
            return;
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }

    sort(arr, n);
    traverse(arr, n);
}