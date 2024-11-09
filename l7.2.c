#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue function to add element to the end of the queue
void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element %d added to the queue.\n", value);
}

// Dequeue function to remove element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty, cannot dequeue.\n");
    } else {
        struct Node *temp = front;
        front = front->next;
        printf("Element %d deleted from the queue.\n", temp->data);
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
    }
}

// Check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Traverse function to print all elements in the queue
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            if (isEmpty()) {
                printf("Queue is empty.\n");
            } else {
                printf("Queue is not empty.\n");
            }
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}
