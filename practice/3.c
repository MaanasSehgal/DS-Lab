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

void kthLastElement(struct Node **head, int k)
{
    struct Node *slow = *head, *fast = *head;

    int kOutOfRange = 0;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
        if (fast == NULL)
        {
            kOutOfRange = 1;
            break;
        }
    }
    if (kOutOfRange == 1)
    {
        printf("K is out of range");
    }
    else
    {
        slow = *head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        printf("%d is the kth last element", slow->val);
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

    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    kthLastElement(&head, k);
}