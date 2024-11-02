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

void deleteDuplicates(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct Node *curr = *head;
    while (curr != NULL && curr->next != NULL) {
        struct Node *t = curr;
        while (t->next != NULL) {
            if (t->next->val == curr->val) {
                struct Node *duplicate = t->next;
                t->next = t->next->next;
                free(duplicate);
            } else {
                t = t->next;
            }
        }
        curr = curr->next;
    }
}

int main() {
    struct Node *head;
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertVal(&head, val);
    }

    deleteDuplicates(&head);
    printLL(head);
}