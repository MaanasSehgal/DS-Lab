#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *stack = NULL;

int isEmpty()
{
    if (stack == NULL)
        return 1;
    else
        return 0;
    printf("\n");
}

void display()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = stack;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void push(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = stack;
    stack = temp;
}

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = stack;
    stack = stack->next;
    free(temp);
}

int main()
{
    int operation = 0, val = 0;
    while (operation != 5)
    {
        printf("\n------------------------\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) isEmpty()\n");
        printf("4) Display stack elements\n");
        printf("5) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
        {
            // push
            printf("Enter the value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            if (isEmpty() == 1)
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
            display();
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            printf("Enter a valid choice: ");
            break;
        }
        }
    }
}