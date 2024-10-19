#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void traverseLL(struct Node **head)
{
    struct Node *temp = *head;
    if (*head == NULL)
    {
        printf("Empty linkedlist\n");
        return;
    }
    else
    {
        printf("%d -> ", (*head)->val);
        temp = temp->next;
        while (temp != NULL && temp != *head)
        {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}

void insertInCircularLL(struct Node **head, int val, int i, int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        if (i == n)
        {
            newNode->next = *head;
        }
    }

    printf("New Linked List: ");
    traverseLL(head);
}

int main()
{
    struct Node *head = NULL;
    int n;
    printf("Enter the initial number of nodes in LL: ");
    scanf("%d", &n);
    printf("Enter the elements of LL: ");
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        insertInCircularLL(&head, val, i + 1, n);
    }
    return 0;
}