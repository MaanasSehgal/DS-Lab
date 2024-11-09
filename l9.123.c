#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *search(struct Node *root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

struct Node *findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int findMax(struct Node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int findMinValue(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int height(struct Node *root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeafNodes(struct Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node *root = NULL;
    int choice, n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Preorder Traversal\n2. Postorder Traversal\n3. Inorder Traversal\n4. Search\n5. Insert\n6. Delete\n");
        printf("7. Find Largest\n8. Find Smallest\n9. Height of Tree\n10. Count Leaf Nodes\n11. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
                printf("Element %d found in BST.\n", data);
            else
                printf("Element %d not found in BST.\n", data);
            break;
        case 5:
            printf("Enter element to insert in BST: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Element %d inserted in BST.\n", data);
            break;
        case 6:
            printf("Enter element to delete from BST: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Element %d deleted from BST.\n", data);
            break;
        case 7:
            if (root != NULL)
                printf("Largest element in BST = %d\n", findMax(root));
            else
                printf("BST is empty.\n");
            break;
        case 8:
            if (root != NULL)
                printf("Smallest element in BST = %d\n", findMinValue(root));
            else
                printf("BST is empty.\n");
            break;
        case 9:
            printf("Height of the BST = %d\n", height(root));
            break;
        case 10:
            printf("Number of leaf nodes in BST = %d\n", countLeafNodes(root));
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
