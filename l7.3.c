#include <stdio.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Element deleted\n");
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX == front;
}

void traverse() {
    if (isEmpty()) {
        printf("CQueue: Empty\n");
    } else {
        printf("CQueue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int option, element;

    printf("Enter Queue size: %d\n", MAX);

    while (1) {
        printf("Main Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Queue Empty: %s\n", isEmpty() ? "True" : "False");
            break;
        case 4:
            printf("Queue Full: %s\n", isFull() ? "True" : "False");
            break;
        case 5:
            traverse();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option\n");
        }
    }
}
