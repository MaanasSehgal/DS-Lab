#include <stdio.h>

int max = 0, top = -1;

int isEmpty(int stack[])
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull(int stack[])
{
    if (top + 1 == max)
        return 1;
    else
        return 0;
}

void push(int stack[], int val)
{
    if (isFull(stack) == 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = val;
}

void pop(int stack[])
{
    if (isEmpty(stack) == 1)
    {
        printf("Stack is empty\n");
        return;
    }
    int val = stack[top--];
    printf("Popped element %d", val);
}

void display(int stack[])
{
    if (isEmpty(stack) == 1)
        return;

    int val = stack[top--];

    printf("%d ", val);
    display(stack);
    push(stack, val);
}

int main()
{
    printf("Enter the maximum number of elements in stack: ");
    scanf("%d", &max);

    int stack[max];

    int operation = 0, val = 0;
    while (operation != 6)
    {
        printf("\n------------------------\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) isEmpty()\n");
        printf("4) isFull()\n");
        printf("5) Display stack elements\n");
        printf("6) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            // push
            printf("Enter the value to push: ");
            scanf("%d", &val);
            push(stack, val);
            break;
        }
        case 2:
        {
            pop(stack);
            break;
        }
        case 3:
        {
            if (isEmpty(stack) == 1)
            {
                printf("Stack is empty\n\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        }
        case 4:
        {
            if (isFull(stack) == 1)
            {
                printf("Stack is full\n\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        }
        case 5:
        {
            display(stack);
            break;
        }
        case 6:
        {
            return;
        }
        default:
        {
            printf("Enter a valid choice: ");
            break;
        }
        }
    }
}