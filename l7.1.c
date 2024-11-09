#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

void initQueue(struct Queue *q, int size) {
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == q->size - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = value;
    printf("Element %d enqueued.\n", value);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Element %d dequeued.\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void traverse(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    int size, choice, value;

    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    initQueue(&q, size);

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            if (isEmpty(&q))
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 4:
            if (isFull(&q))
                printf("Queue is full.\n");
            else
                printf("Queue is not full.\n");
            break;
        case 5:
            traverse(&q);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
