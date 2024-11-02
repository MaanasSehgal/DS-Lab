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
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertSort(struct Node **head, int val, int pos)
{
    // struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // newNode->val = val;

    // if (pos == 1)
    // {
    //     newNode->next = *head;
    //     *head = newNode;
    // }
    // else
    // {
    //     struct Node *temp = *head;
    //     for (int i = 0; i < pos - 2; i++)
    //     {
    //         if (temp->next == NULL)
    //         {
    //             printf("Incorrect position\n");
    //             return;
    //         }
    //         temp = temp->next;
    //     }
    //     newNode->next = temp->next;
    //     temp->next = newNode;
    // }
    // printf("New Linked List: ");
    // traverseLL(head);
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

    int option = 0;
    while (option != 4)
    {
        printf("\n**MENU FOR PRIORITY QUEUE**\n");
        printf("1) Enqueue\n");  // insert sort
        printf("2) Dequeue\n");  // delete front
        printf("3) Traverse\n"); // traverse ll
        printf("4) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        int val, pos;
        switch (option)
        {
        case 1:
            printf("Enter the val: ");
            scanf("%d", &val);
            head = insertSort(head, val);
            break;
        case 2:
            deleteAtPosition(&head, 1);
            break;
        case 3:
            traverseLL(&head);
            break;
        case 4:
            return 0;
        default:
            printf("Enter a valid choice: ");
            break;
        }
    }
    return 0;
}