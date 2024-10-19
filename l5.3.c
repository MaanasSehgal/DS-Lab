#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int val;
    struct Node *next;
};

struct Head
{
    int row;
    int col;
    int nonZeros;
    struct Node *next;
};

void traverseLL(struct Head **head)
{
    printf("%d | %d | %d\n", (*head)->row, (*head)->col, (*head)->nonZeros);
    printf("---------\n");
    struct Node *p = (*head)->next;

    while (p != NULL)
    {
        printf("%d | %d | %d\n", p->row, p->col, p->val);
        p = p->next;
    }
}

void push(struct Head **head, struct Node **q, int i, int j, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->row = i;
    temp->col = j;
    temp->val = val;
    temp->next = NULL;

    if ((*q) == NULL)
    {
        (*head)->next = temp;
        *q = temp;
    }
    else
    {
        (*q)->next = temp;
        *q = temp;
    }
}

void input(struct Head **head)
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    (*head)->row = m;
    (*head)->col = n;
    (*head)->nonZeros = 0;

    struct Node *q = NULL;
    int val;

    printf("Enter the matrix values (row-wise): ");
    for (int i = 0; i < (*head)->row; i++)
    {
        for (int j = 0; j < (*head)->col; j++)
        {
            scanf("%d", &val);

            if (val != 0)
            {
                (*head)->nonZeros++;
                push(head, &q, i, j, val);
            }
        }
    }
}

void add(struct Head **head1, struct Head **head2, struct Head **res)
{
    if ((*head1)->row != (*head2)->row || (*head1)->col != (*head2)->col)
    {
        printf("Matrices are not of the same size\n");
        return;
    }

    (*res)->row = (*head1)->row;
    (*res)->col = (*head1)->col;

    struct Node *p1 = (*head1)->next;
    struct Node *p2 = (*head2)->next;
    struct Node *q = NULL;

    int nonZeros = 0;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->row == p2->row && p1->col == p2->col)
        {
            if (p1->val + p2->val != 0)
            {
                push(res, &q, p1->row, p1->col, p1->val + p2->val);
                nonZeros++;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->row < p2->row || (p1->row == p2->row && p1->col < p2->col))
        {
            push(res, &q, p1->row, p1->col, p1->val);
            nonZeros++;
            p1 = p1->next;
        }
        else
        {
            push(res, &q, p2->row, p2->col, p2->val);
            nonZeros++;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        push(res, &q, p1->row, p1->col, p1->val);
        nonZeros++;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        push(res, &q, p2->row, p2->col, p2->val);
        nonZeros++;
        p2 = p2->next;
    }

    (*res)->nonZeros = nonZeros;
}

int main()
{
    struct Head *head1 = (struct Head *)malloc(sizeof(struct Head));
    head1->next = NULL;

    input(&head1);

    struct Head *head2 = (struct Head *)malloc(sizeof(struct Head));
    head2->next = NULL;

    input(&head2);

    struct Head *res = (struct Head *)malloc(sizeof(struct Head));
    res->next = NULL;

    printf("\nMatrix 1:\n");
    traverseLL(&head1);

    printf("\nMatrix 2:\n");
    traverseLL(&head2);

    add(&head1, &head2, &res);

    printf("\nResultant Matrix:\n");
    traverseLL(&res);

    return 0;
}
