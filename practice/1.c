#include <stdio.h>
#include <stdlib.h>

// find middle node of ll
struct Node
{
    int val;
    struct Node *next;
};

void push(struct Node **head, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct Node *q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}

void traverse(struct Node **head)
{
    struct Node *q;
    if (*head != NULL)
    {

        for (q = *head; q != NULL; q = q->next)
        {
            printf("%d -> ", q->val);
        }
        printf("NULL\n");
    }
}

int findMiddleElement(struct Node **head)
{
    if (*head == NULL)
    {
        return -1;
    }
    else if ((*head)->next == NULL)
    {
        return (*head)->val;
    }
    else
    {
        struct Node *slow = *head, *fast = *head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->val;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, val;

    printf("Enter the size of LL: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        push(&head, val);
    }

    // traverse(&head);
    printf("Middle element: %d", findMiddleElement(&head));
}