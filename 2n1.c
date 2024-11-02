#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

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

void printLL(struct Node *head) {
    printf("The linked list is: ");
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void searchDeleteAndInsertAtBeginning(struct Node **head, int searchValue) {
    int countOfSearchValue = 0;
    while (*head != NULL && (*head)->val == searchValue) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        countOfSearchValue++;
    }

    struct Node *temp = *head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->val == searchValue) {
            struct Node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            countOfSearchValue++;
        } else {
            temp = temp->next;
        }
    }

    for (int i = 0; i < countOfSearchValue; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = searchValue;
        newNode->next = *head;
        *head = newNode;
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

    printf("Enter the search value: ");
    int searchValue;
    scanf("%d", &searchValue);

    searchDeleteAndInsertAtBeginning(&head, searchValue);
    printLL(head);
}