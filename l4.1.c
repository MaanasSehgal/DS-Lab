#include <stdio.h>
#include <stdlib.h>

// Write a C program to create a single linkedlist of n nodes and perform the following menu based operations on it using function
// 1) Insert at beginning
// 2) Insert at end
// 3) Insert at any location
// 4) Traverse a LL
// 5) Count the number of nodes in a linkedlist
// 6) Search an element
// 7) Exit

// create(&head);

// void create(int n, struct Node **head)
// {
//     printf('Enter the elements of the ll");

//     int val;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &val);
//         insertAtEnd(val);
//     }
// }

struct Node
{
    int val;
    struct Node *next;
};

void traverseLL(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    printf("New Linked List: ");
    traverseLL(&head);
    return head;
}

void insertAtEnd(struct Node **head, int val)
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
    }
    printf("New Linked List: ");
    traverseLL(head);
}

void insertAtPosition(struct Node **head, int val, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 0; i < pos - 2; i++)
        {
            if (temp->next == NULL)
            {
                printf("Incorrect position\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("New Linked List: ");
    traverseLL(head);
}

int countNodes(struct Node **head)
{
    struct Node *temp = *head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Count of nodes: %d\n", count);
    return count;
}

int searchElement(struct Node **head, int target)
{
    struct Node *temp = *head;
    int idx = 1;
    while (temp != NULL)
    {
        if (temp->val == target)
        {
            printf("Found target at index: %d\n", idx);
            return idx;
        }
        temp = temp->next;
        idx++;
    }
    printf("Element not found\n");
    return -1;
}

void sortLL(struct Node **head)
{
    struct Node *p, *q;

    for (p = *head; p != NULL; p = p->next)
    {
        int swapFlag = 0;
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->val > q->val)
            { // swap
                swapFlag = 1;
                int temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
        }
        if (swapFlag == 0)
            break;
    }
    printf("New Linked List: ");
    traverseLL(head);
}

void reverseLL(struct Node **head)
{
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("New Linked List: ");
    traverseLL(head);
}

void deleteAtPosition(struct Node **head, int pos)
{
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("Empty LL\n");
        return;
    }
    else if (pos == 1)
    { // del from beg
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            if (temp->next == NULL)
            {
                printf("Incorrect position\n");
                return;
            }
            temp = temp->next;
        }
        struct Node *temp2 = temp->next;
        if (temp2 != NULL)
            temp->next = temp2->next;
        free(temp2);
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
        insertAtEnd(&head, val);
    }

    int option = 0;
    while (option != 10)
    {
        printf("\n**MENU**\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at end\n");
        printf("3) Insert at location\n");
        printf("4) Traverse LL\n");
        printf("5) Count nodes\n");
        printf("6) Search an element\n");
        printf("7) Sort the linkedlist\n");
        printf("8) Reverse the linkedlist\n");
        printf("9) Deletion from position\n");
        printf("10) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        int val, pos;
        switch (option)
        {
        case 1:
            printf("Enter the element to insert at beginning: ");
            scanf("%d", &val);
            head = insertAtBeginning(head, val);
            break;
        case 2:
            printf("Enter the element to insert at end: ");
            scanf("%d", &val);
            insertAtEnd(&head, val);
            break;
        case 3:
            printf("Enter the element and position to insert: ");
            scanf("%d %d", &val, &pos);
            insertAtPosition(&head, val, pos);
            break;
        case 4:
            traverseLL(&head);
            break;
        case 5:
            countNodes(&head);
            break;
        case 6:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            searchElement(&head, val);
            break;
        case 7:
            sortLL(&head);
            break;
        case 8:
            reverseLL(&head);
            break;
        case 9:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 10:
            printf("Exiting code");
            break;
        default:
            printf("Enter a valid choice: ");
            break;
        }
    }
    return 0;
}