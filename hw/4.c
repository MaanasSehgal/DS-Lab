#include <stdio.h>
#include <stdlib.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void numBetweenElements(int *arr, int n, int a, int b)
{
    int aIdx = -1, bIdx = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a && aIdx == -1)
        {
            aIdx = i;
        }
        else if (arr[i] == b && bIdx == -1)
        {
            bIdx = i;
        }
    }

    if (aIdx == -1 || bIdx == -1)
    {
        printf("Either a or b is missing");
        return;
    }

    if (arr[aIdx] > arr[bIdx])
    { // swap
        int temp = aIdx;
        aIdx = bIdx;
        bIdx = temp;
    }

    for (int i = aIdx; i <= bIdx; i++)
    {
        printf("%d ", arr[i]);
    }
}

void findNextGreaterElement(int *arr, int n)
{
    int *nextGreater = (int *)malloc(n * sizeof(int));
    nextGreater[n - 1] = -1;
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

    findNextGreaterElement(arr, n);
}