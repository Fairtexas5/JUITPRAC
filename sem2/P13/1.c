#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = delete(root->right, minRight->data);
    }
    
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)
        return search(root->left, data);
    
    return search(root->right, data);
}

void printMenu() {
    printf("\nBinary Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Delete\n");
    printf("6. Search\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Data deleted successfully.\n");
                break;
            case 6:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct Node* result = search(root, data);
                if (result != NULL)
                    printf("Data found in the binary tree.\n");
                else
                    printf("Data not found in the binary tree.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
