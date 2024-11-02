#include <stdio.h>

int deque[100];
int front, rear;

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

int isFull()
{
    if ((rear + 1) % 100 == front)
        return 1;
    return 0;
}

void traverse()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i != rear; i = (i + 1) % 100)
    {
        printf("%d ", deque[i]);
    }
    printf("%d\n", deque[rear]);
}

void insertLeft(int val)
{
    if (isFull())
    {
        printf("Deque is full, can't insert value\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + 100) % 100;

    deque[front] = val;
}

void insertRight(int val)
{
    if (isFull())
    {
        printf("Deque is full, can't insert value\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % 100;

    deque[rear] = val;
}

void deleteLeft()
{
    if (isEmpty())
    {
        printf("Deque is empty, can't delete value\n");
        return;
    }

    front = (front + 1) % 100;

    if (front == rear)
    {
        front = rear = -1;
    }
}

void deleteRight()
{
    if (isEmpty())
    {
        printf("Deque is empty, can't delete value\n");
        return;
    }

    rear = (rear - 1 + 100) % 100;

    if (front == rear)
    {
        front = rear = -1;
    }
}

int main()
{
    front = -1;
    rear = -1;

    int option = 0, val = 0;
    while (option != 8)
    {
        printf("**MENU**\n");
        printf("1) Insert at left\n");
        printf("2) Insert at right\n");
        printf("3) Delete at left\n");
        printf("4) Delete at right\n");
        printf("5) Display\n");
        printf("6) Is Empty\n");
        printf("7) Is Full\n");
        printf("8) Exit\n\n");
        printf("Enter the choice: ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insertLeft(val);
            traverse();
            break;
        }

        case 2:
        {
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insertRight(val);
            traverse();
            break;
        }

        case 3:
        {
            deleteLeft();
            traverse();
            break;
        }

        case 4:
        {
            deleteRight();
            traverse();
            break;
        }

        case 5:
        {
            traverse();
            break;
        }

        case 6:
        {
            if (isEmpty() == 1)
                printf("Deque is empty\n");
            else
                printf("Deque is empty\n");
            break;
        }

        case 7:
        {
            if (isFull())
                printf("Deque is full\n");
            else
                printf("Deque is not full\n");
            break;
        }

        case 8:
        {
            return 0;
        }
        }
    }
}