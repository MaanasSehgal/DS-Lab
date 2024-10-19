#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
};

void traverseLL(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d <--> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtPosition(struct Node **head, int val, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;

    if (pos == 1)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }
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
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("New Linked List: ");
    traverseLL(head);
}

void deleteAtPosition(struct Node **head, int pos)
{
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("\nEmpty LL\n");
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
                printf("\nIncorrect position\n");
                return;
            }
            temp = temp->next;
        }
        struct Node *temp2 = temp->next;
        if (temp2 == NULL)
        {
            printf("\nIncorrect Position\n");
            return;
        }
        temp->next = temp->next->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
        free(temp2);
    }
    printf("New Linked List: ");
    traverseLL(head);
}

int main()
{
    struct Node *head = NULL;
    int n;
    printf("Enter the initial number of nodes in Doubly LL: ");
    scanf("%d", &n);
    printf("Enter the elements of LL: ");
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        insertAtPosition(&head, val, i + 1);
    }

    int option = 0;
    while (option != 10)
    {
        printf("\n**MENU**\n");
        printf("1) Insert at position\n");
        printf("2) Deletion from position\n");
        printf("3) Traverse LL\n");
        printf("4) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        int val, pos;
        switch (option)
        {
        case 1:
            printf("Enter the element and position to insert: ");
            scanf("%d %d", &val, &pos);
            insertAtPosition(&head, val, pos);
            break;
        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 3:
            traverseLL(&head);
            break;
        case 4:
            printf("Exiting code");
            break;
        default:
            printf("Enter a valid choice: ");
            break;
        }
    }
    return 0;
}