#include <stdio.h>

// 1.1 Write a program to read two numbers and compare the numbers using function call by address.
// Sample Input:
// Enter two numbers: 50  80
// Sample Output:
// 50 is smaller than 80
// Sample Input:
// Enter two numbers: 40  10
// Sample Output:
// 40 is greater than 10
// Sample Input:
// Enter two numbers: 50  50
// Sample Output:
// Both numbers are same
void compare(int *a, int *b)
{
    if (*a > *b)
    {
        printf("%d is greater than %d\n", *a, *b);
    }
    else if (*a < *b)
    {
        printf("%d is smaller than %d\n", *a, *b);
    }
    else
    {
        printf("Both numbers are same\n");
    }
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    compare(&a, &b);
    return 0;
}