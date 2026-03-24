//CH.SC.U4CSE24155
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} Node;

// Function to get height
int height(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Max function
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(Node *n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// Insert into AVL
Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Level order traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node* temp = queue[front++];
            printf("%d ", temp->data);

            if (temp->left)
                queue[rear++] = temp->left;
            if (temp->right)
                queue[rear++] = temp->right;
        }
        printf("\n"); // new level
    }
}

// Check AVL balance
int checkAVL(Node* root) {
    if (root == NULL) return 1;

    int balance = getBalance(root);

    if (balance > 1 || balance < -1)
        return 0;

    return checkAVL(root->left) && checkAVL(root->right);
}

// Main
void main() {
    Node* root = NULL;

    int arr[] = {157, 110, 147, 122, 149, 151, 111, 141, 112, 123, 133, 117};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Level-wise AVL Tree:\n");
    levelOrder(root);

    if (checkAVL(root))
        printf("\nTree is balanced (AVL)\n");
    else
        printf("\nTree is NOT balanced\n");
}