#include <stdio.h>

struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *start = (struct Node *)malloc(sizeof(struct Node));

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
}