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

struct Node* findNode(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return findNode(root->left, data);

    return findNode(root->right, data);
}

struct Node* findMaxNode(struct Node* node) {
    if (node == NULL)
        return NULL;

    while (node->right != NULL)
        node = node->right;

    return node;
}

struct Node* findMinNode(struct Node* node) {
    if (node == NULL)
        return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

void findPredecessorSuccessor(struct Node* root, int data, struct Node** predecessor, struct Node** successor) {
    if (root == NULL)
        return;

    struct Node* current = findNode(root, data);
    if (current == NULL)
        return;

    if (current->left != NULL)
        *predecessor = findMaxNode(current->left);

    if (current->right != NULL)
        *successor = findMinNode(current->right);
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
    int data, numNodes, target;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Enter the data of the node to find its predecessor and successor: ");
    scanf("%d", &target);

    struct Node* predecessor = NULL;
    struct Node* successor = NULL;

    findPredecessorSuccessor(root, target, &predecessor, &successor);

    if (predecessor != NULL)
        printf("Predecessor: %d\n", predecessor->data);
    else
        printf("Predecessor not found.\n");

    if (successor != NULL)
        printf("Successor: %d\n", successor->data);
    else
        printf("Successor not found.\n");

    freeTree(root);

    return 0;
}
