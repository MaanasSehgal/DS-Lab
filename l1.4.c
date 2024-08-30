#include <stdio.h>

typedef struct
{
    int real;
    int imag;
} ComplexNumber;

ComplexNumber addComplexNumber(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

void multiplyComplexNumber(ComplexNumber *a, ComplexNumber *b, ComplexNumber *result)
{
    result->real = a->real * b->real - a->imag * b->imag;
    result->imag = a->real * b->imag + a->imag * b->real;
}

int main()
{
    ComplexNumber n1, n2, result;
    int choice;

    printf("Enter complex number 1 -> ");
    scanf("%d %d", &n1.real, &n1.imag);

    printf("Enter complex number 2 -> ");
    scanf("%d %d", &n2.real, &n2.imag);

    printf("\nMENU\n1. addition\n2. multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        result = addComplexNumber(n1, n2);
        printf("Sum = %d + %di\n", result.real, result.imag);
    }
    else if (choice == 2)
    {
        multiplyComplexNumber(&n1, &n2, &result);
        printf("Product = %d + %di\n", result.real, result.imag);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
