#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* createNode(int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

NODE* insert(NODE* root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

void preorderTraversal(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(NODE* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(NODE* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

NODE* findMin(NODE* root) {
    while (root->left != NULL)
        root = root->left;
    
    return root;
}

NODE* delete(NODE* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
        
        NODE* minRight = findMin(root->right);
        root->data = minRight->data;
        root->right = delete(root->right, minRight->data);
    }
    
    return root;
}

NODE* search(NODE* root, int data) {
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
    NODE* root = NULL;
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
                NODE* result = search(root, data);
                if (result != NULL)
                    printf("Data found\n");
                else
                    printf("Data not found\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    
    return 0;
}
