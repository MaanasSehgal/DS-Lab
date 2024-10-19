#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int pow;
    int val;
    struct Node *next;
};

void traverseLL(struct Node **head)
{
    if (*head == NULL)
    {
        printf("NULL\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    temp = prev;
    while (temp != NULL)
    {
        printf("%dx^%d -> ", temp->val, temp->pow);
        temp = temp->next;
    }
    printf("NULL\n");
}

void push(struct Node **poly, int pow, int coeff)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->val = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (*poly == NULL)
    {
        *poly = newNode;
        return;
    }
    else
    {
        struct Node *temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void inputPolynomial(struct Node **poly)
{
    int maxDeg, coeff;

    printf("Enter max degree for the polynomial: ");
    scanf("%d", &maxDeg);

    printf("Enter the coefficients for respective degree of x: \n");
    for (int i = 0; i <= maxDeg; i++)
    {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        push(poly, i, coeff);
    }
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *temp1 = poly1, *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->pow == temp2->pow)
        {
            push(&result, temp1->pow, temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->pow > temp2->pow)
        {
            push(&result, temp1->pow, temp1->val);
            temp1 = temp1->next;
        }
        else
        {
            push(&result, temp2->pow, temp2->val);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        push(&result, temp1->pow, temp1->val);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        push(&result, temp2->pow, temp2->val);
        temp2 = temp2->next;
    }

    return result;
}

void printSum(struct Node **poly)
{
    if (*poly == NULL)
    {
        printf("0\n");
        return;
    }

    struct Node *temp = *poly;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    temp = prev;
    int firstTerm = 1;

    while (temp != NULL)
    {
        if (temp->val != 0)
        {
            if (!firstTerm)
                printf(" + ");

            if (temp->pow == 0)
                printf("%d", temp->val);
            else if (temp->pow == 1)
            {
                if (temp->val == 1)
                    printf("x");
                else
                    printf("%dx", temp->val);
            }
            else
            {
                if (temp->val == 1)
                    printf("x^%d", temp->pow);
                else
                    printf("%dx^%d", temp->val, temp->pow);
            }

            firstTerm = 0;
        }
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;

    printf("Polynomial 1 Input:\n");
    inputPolynomial(&poly1);

    printf("Polynomial 2 Input:\n");
    inputPolynomial(&poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomial 1 and Polynomial 2: ");
    printSum(&sum);

    return 0;
}
