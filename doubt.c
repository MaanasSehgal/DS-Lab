#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
} *start;

void createlist(int n)
{
    struct node *temp, *new;
    int data;
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Unable.");
    }

    printf("Enter data   of node 1:");
    scanf("%d", &data);
    start->info = data;
    start->next = NULL;
    temp = start;

    for (int i = 2; i <= n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data   of node %d:", i);
        scanf("%d", &data);
        new->info = data;
        new->next = NULL;

        temp->next = new;
        temp = temp->next;
    }
}

void insert_bef(struct node **start, int data, int bef)
{
    struct node *q, *temp, *prev;

    if (*start == NULL)
        return;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    for (q = *start; q != NULL && q->info != bef; prev = q, q = q->next)
        ;
    if (q == NULL)
        return;

    temp->next = q->next;
    prev->next = q;

    prev->next = temp;
    temp->next = q;
}

void traversal(struct node *start)
{
    struct node *q;
    if (start == NULL)
        return;
    else
    {
        for (q = start; q != NULL; q = q->next)
            printf("%d ", q->info);
    }
}

int main()
{
    int n;
    int data;
    int bef;
    printf("enter total number of node:");
    scanf("%d", &n);
    createlist(n);
    printf("Enter the new element to be inserted:");
    scanf("%d", &data);
    printf("Enter the element before which the element will be inserted :");
    scanf("%d", &bef);
    insert_bef(&start, data, bef);
    traversal(start);
}