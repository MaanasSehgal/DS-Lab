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
        temp = temp->next;
    }
    printf("NULL\n");
}

int countOccurances(struct Node *head, int target) {
    int count = 0;

    struct Node *temp = head;
    while (temp != NULL) {
        if (temp -> val == target) {
            count++;
        }
        temp = temp->next;
    }
    return count;
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

    printf("Enter the value to get it's number of occurances: ");
    int target;
    scanf("%d", &target);

    int occurances = countOccurances(head, target);
    printf("The number of occurances of %d is: %d\n", target, occurances);
}