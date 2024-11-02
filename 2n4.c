#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void printLL(struct Node *head) {
    printf("The linked list is: ");
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertSort(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    } else if (val < (*head)->val) {
        newNode->next = *head;
        *head = newNode;
        return;
    } else {
        struct Node *temp = *head;
        while (temp -> next != NULL && temp->next->val < val) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertVal(struct Node **head, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    struct Node *head;
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);

    printf("Enter the values in sorted order: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertVal(&head, val);
    }

    printf("Enter the value to insert: ");
    int valToInsert;
    scanf("%d", &valToInsert);

    insertSort(&head, valToInsert);
    printLL(head);
}