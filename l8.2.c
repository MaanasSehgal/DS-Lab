#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *createNode(int data, int priority) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node **head, int data, int priority) {
    struct Node *newNode = createNode(data, priority);
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Element %d added with priority %d.\n", data, priority);
}

void dequeue(struct Node **head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Removed element with data %d and priority %d.\n", temp->data, temp->priority);
    free(temp);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue:\nPriority\tItem\n");
    while (head != NULL) {
        printf("%d\t\t%d\n", head->priority, head->data);
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data, priority;

    while (1) {
        printf("Main Menu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(&head, data, priority);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
