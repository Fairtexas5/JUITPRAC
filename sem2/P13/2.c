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

void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear] = root;
    
    while (front <= rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }

    free(queue);
}

void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int data, numNodes;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &numNodes);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}
