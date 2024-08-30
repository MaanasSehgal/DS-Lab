#include <stdio.h>
#include <stdlib.h>

void traverse(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
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

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int temp = *(arr + start);
        *(arr + start) = *(arr + end);
        *(arr + end) = temp;
        start++;
        end--;
    }

    traverse(arr, n);
}