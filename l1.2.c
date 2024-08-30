#include <stdio.h>
#include <stdlib.h>

void sieveOfEratosthenes(int *prime, int n)
{
    for (int i = 0; i < n; i++)
    {
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int sumOfPrimes(int *arr, int n)
{
    int sum = 0, size = 100;
    int prime[size];

    sieveOfEratosthenes(prime, size);

    for (int i = 0; i < n; i++)
    {
        if (prime[arr[i]] == 1)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = sumOfPrimes(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}
