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

int findLength(struct Node *head)
{
    if (head == NULL)
        return 0;
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

void findMergingPoint(struct Node *head1, struct Node *head2)
{
    int length1 = findLength(head1);
    int length2 = findLength(head2);

    struct Node *q1 = head1, *q2 = head2;

    if (length1 > length2)
    {
        for (int i = 0; i < length1 - length2; i++)
        {
            q1 = q1->next;
        }
    }
    else
    {
        for (int i = 0; i < length2 - length1; i++)
        {
            q2 = q2->next;
        }
    }

    // both on same node
    while (q1 != q2)
    {
        q1 = q1->next;
        q2 = q2->next;
    }

    traverse(head1);
    traverse(head2);
    printf("Meeting node: %d", q1->val);
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);

    push(&head2, 10);
    push(&head2, 20);
    push(&head2, 30);

    struct Node *temp1 = head1;
    for (int i = 0; i < 2; i++)
    {
        temp1 = temp1->next;
    }

    struct Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;

    findMergingPoint(head1, head2);
    return 0;
}
