//CH.SC.U4CSE24155
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    char color; // 'R' or 'B'
    struct Node *left, *right, *parent;
} Node;

Node *root = NULL;

// Create new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = 'R';
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left rotate
void leftRotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right rotate
void rightRotate(Node *y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix Red-Black violations
void fixInsert(Node *z) {
    while (z->parent != NULL && z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;

            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;

            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 'B';
}

// Insert node
void insert(int data) {
    Node *z = newNode(data);
    Node *y = NULL;
    Node *x = root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(z);
}

// Level order print with color
void levelOrder() {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node* temp = queue[front++];
            printf("%d(%c) ", temp->data, temp->color);

            if (temp->left)
                queue[rear++] = temp->left;
            if (temp->right)
                queue[rear++] = temp->right;
        }
        printf("\n");
    }
}

// Check root black
int isRootBlack() {
    if (root == NULL) return 1;
    return (root->color == 'B');
}

// Check no red-red violation
int checkRedViolation(Node *node) {
    if (node == NULL) return 1;

    if (node->color == 'R') {
        if ((node->left && node->left->color == 'R') ||
            (node->right && node->right->color == 'R'))
            return 0;
    }

    return checkRedViolation(node->left) &&
           checkRedViolation(node->right);
}

// Main
void main() {
    int arr[] = {157, 110, 147, 122, 149, 151, 111, 141, 112, 123, 133, 117};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    printf("Level-wise Red-Black Tree:\n");
    levelOrder();

    if (isRootBlack())
        printf("\nRoot is BLACK\n");
    else
        printf("\nRoot is NOT BLACK\n");

    if (checkRedViolation(root))
        printf("No red-red violation\n");
    else
        printf("Red-red violation exists\n");
}