#include <stdio.h>

int stack[100], top1 = -1, top2 = 100, n = 100;

int main() {
    // 2 stacks in one array
    int choice = 0;

    while (choice != 7) {
        printf("**MENU**\n");
        printf("1. Push in stack 1\n");
        printf("2. Push in stack 2\n");
        printf("3. Pop from stack 1\n");
        printf("4. Pop from stack 2\n");
        printf("5. Display stack 1\n");
        printf("6. Display stack 2\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (top1 < top2 - 1) {
                printf("Enter the element to push in stack 1: ");
                int ele;
                scanf("%d", &ele);
                stack[++top1] = ele;
            } else {
                printf("Stack 1 is full\n");
            }
            break;
        case 2:
            if (top1 < top2 - 1) {
                printf("Enter the element to push in stack 2: ");
                int ele;
                scanf("%d", &ele);
                stack[--top2] = ele;
            } else {
                printf("Stack 2 is full\n");
            }
            break;
        case 3:
            if (top1 >= 0) {
                printf("Popped element from stack 1: %d\n", stack[top1--]);
            } else {
                printf("Stack 1 is empty\n");
            }
            break;
        case 4:
            if (top2 < n) {
                printf("Popped element from stack 2: %d\n", stack[top2++]);
            } else {
                printf("Stack 2 is empty\n");
            }
            break;
        case 5:
            if (top1 >= 0) {
                printf("Stack 1: ");
                for (int i = 0; i <= top1; i++) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            } else {
                printf("Stack 1 is empty\n");
            }
            break;
        case 6:
            if (top2 < n) {
                printf("Stack 2: ");
                for (int i = n - 1; i >= top2; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            } else {
                printf("Stack 2 is empty\n");
            }
            break;
        case 7:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}