#include <stdio.h>
#include <stdlib.h>

// 2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array

void traverseArray(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void insertElement(int **nums, int *n, int element, int position)
{
    if (position < 0 || position > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    *n = *n + 1;
    int *temp = realloc(*nums, sizeof(int) * (*n));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    *nums = temp;

    for (int i = *n - 1; i > position; i--)
    {
        (*nums)[i] = (*nums)[i - 1];
    }
    (*nums)[position] = element;

    printf("New array: ");
    traverseArray(*nums, *n);
}

void deleteElement(int *nums, int *n, int position)
{
    if (position < 0 || position >= *n)
    {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *n - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    *n = *n - 1;
    int *temp = realloc(nums, sizeof(int) * (*n));
    if (temp != NULL || *n == 0)
    {
        nums = temp;
    }

    printf("Value of n updated to %d\n", *n);
    printf("New array: ");
    traverseArray(nums, *n);
}

int linearSearch(int *nums, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int option, element, position;
    do
    {
        printf("***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Element to insert: ");
            scanf("%d", &element);
            printf("Enter Position: ");
            scanf("%d", &position);
            insertElement(&nums, &n, element, position);
            break;
        case 2:
            printf("Enter Position: ");
            scanf("%d", &position);
            deleteElement(nums, &n, position);
            break;
        case 3:
            printf("Element to search: ");
            scanf("%d", &element);
            position = linearSearch(nums, n, element);
            if (position != -1)
            {
                printf("Element found at position: %d\n", position);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 4:
            printf("Array Elements: ");
            traverseArray(nums, n);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (option != 5);

    free(nums);
    return 0;
}
