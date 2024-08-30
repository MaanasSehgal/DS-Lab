#include <stdio.h>
#include <stdlib.h>

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

void traverse(struct Node *head)
{
    struct Node *q = head;
    while (q != NULL)
    {
        printf("%d -> ", q->val);
        q = q->next;
    }
    printf("NULL\n");
}

int detectAndBreakCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL)
    {
        printf("NO CYCLE FOUND\n");
        return 0;
    }

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    return 1;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->val = 1;
    second->val = 2;
    third->val = 3;
    fourth->val = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; 

    if (detectAndBreakCycle(head))
    {
        printf("Cycle was found and removed.\n");
        traverse(head); 
    }
    else
    {
        printf("No cycle to remove.\n");
    }

    return 0;
}
