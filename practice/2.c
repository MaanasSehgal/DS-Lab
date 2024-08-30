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

struct Node *reverseSecondHalf(struct Node *mid)
{
    struct Node *prev = NULL, *curr = mid, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int checkPalindromeLL(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return 1;
    }

    struct Node *slow = *head, *fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *secondHalf = reverseSecondHalf(slow);
    struct Node *firstHalf = *head;

    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;
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
    if (checkPalindormeLL(&head) == 0)
    {
        printf("The linkedlist is not palindrome");
    }
    else
    {
        printf("The linkedlist is a palindrome");
    }
}