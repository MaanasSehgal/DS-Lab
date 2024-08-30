#include <stdio.h>
#include <stdlib.h>

void printPolynomial(int *polyCoefficient, int maxPow)
{
    if (polyCoefficient[maxPow] != 0)
    {
        if (polyCoefficient[maxPow] == 1)
        {
            printf("x^%d", maxPow);
        }
        else
        {
            printf("%dx^%d", polyCoefficient[maxPow], maxPow);
        }
    }

    for (int i = maxPow - 1; i > 0; i--)
    {
        if (polyCoefficient[i] != 0)
        {
            if (polyCoefficient[i] == 1)
            {
                printf(" + x^%d", i);
            }
            else
            {
                printf(" + %dx^%d", polyCoefficient[i], i);
            }
        }
    }

    if (polyCoefficient[0] != 0)
    {
        printf(" + %d", polyCoefficient[0]);
    }
    printf("\n");
}

void addPolynomials(int *poly1, int *poly2, int *result, int maxPow1, int maxPow2)
{
    int maxPowResult = maxPow1 > maxPow2 ? maxPow1 : maxPow2;

    for (int i = 0; i <= maxPowResult; i++)
    {
        if (i <= maxPow1 && i <= maxPow2)
        {
            result[i] = poly1[i] + poly2[i];
        }
        else if (i <= maxPow1)
        {
            result[i] = poly1[i];
        }
        else
        {
            result[i] = poly2[i];
        }
    }
}

int main()
{
    int maxPow1, maxPow2;

    printf("Enter the max power of x in polynomial 1: ");
    scanf("%d", &maxPow1);

    int *poly1 = (int *)malloc((maxPow1 + 1) * sizeof(int));

    printf("Enter the coefficients of poly 1 from x^0 to x^%d: ", maxPow1);
    for (int i = 0; i <= maxPow1; i++)
    {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the max power of x in polynomial 2: ");
    scanf("%d", &maxPow2);

    int *poly2 = (int *)malloc((maxPow2 + 1) * sizeof(int));

    printf("Enter the coefficients of poly 2 from x^0 to x^%d: ", maxPow2);
    for (int i = 0; i <= maxPow2; i++)
    {
        scanf("%d", &poly2[i]);
    }

    int maxPowResult = maxPow1 > maxPow2 ? maxPow1 : maxPow2;
    int *result = (int *)malloc((maxPowResult + 1) * sizeof(int));

    addPolynomials(poly1, poly2, result, maxPow1, maxPow2);

    printf("\nPolynomial 1: ");
    printPolynomial(poly1, maxPow1);

    printf("Polynomial 2: ");
    printPolynomial(poly2, maxPow2);

    printf("Sum of polynomials: ");
    printPolynomial(result, maxPowResult);

    free(poly1);
    free(poly2);
    free(result);

    return 0;
}
