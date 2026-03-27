#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int data;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

RBNode* createNode(int data) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->data = data;
    node->color = RED; // yeni eklenen her dügüm kirmizi
    node->left = node->right = node->parent = NULL;
    return node;
}

RBNode* root = NULL;

// -----------------------------------------------
// ROTATION FUNCTIONS
// -----------------------------------------------
void rotateLeft(RBNode* x) {
    RBNode* y = x->right;
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

void rotateRight(RBNode* y) {
    RBNode* x = y->left;
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

// -----------------------------------------------
// FIX INSERT VIOLATIONS
// -----------------------------------------------
void fixInsert(RBNode* k) {
    RBNode* parent = NULL;
    RBNode* grandparent = NULL;

    while ((k != root) && (k->color == RED) &&
           (k->parent->color == RED)) {

        parent = k->parent;
        grandparent = parent->parent;

        // CASE A: parent is left child
        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;

            // Case 1: uncle is red — recolor
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            }
            else {
                // Case 2: k is right child — rotate left
                if (k == parent->right) {
                    rotateLeft(parent);
                    k = parent;
                    parent = k->parent;
                }
                // Case 3: k is left child — rotate right
                rotateRight(grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        }

        // CASE B: parent is right child
        else {
            RBNode* uncle = grandparent->left;
			// Case 1: uncle is red — recolor
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            }
            else {
            	// Case 2: k is left child — rotate right
                if (k == parent->left) {
                    rotateRight(parent);
                    k = parent;
                    parent = k->parent;
                }
				// Case 3: k is right child — rotate left
                rotateLeft(grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        }
    }

    root->color = BLACK;
}

// -----------------------------------------------
// INSERT NODE
// -----------------------------------------------
void insert(int data) {
    RBNode* node = createNode(data);
    RBNode* parent = NULL;
    RBNode* current = root;

    // normal BST insert
    while (current != NULL) {
        parent = current;
        if (node->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    node->parent = parent;

    if (parent == NULL)
        root = node;
    else if (node->data < parent->data)
        parent->left = node;
    else
        parent->right = node;

    fixInsert(node);
}

// inorder traversal
void inorder(RBNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d (%s)\n", node->data, node->color == RED ? "RED" : "BLACK");
    inorder(node->right);
}

// -----------------------------------------------
// TEST
// -----------------------------------------------
int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(25);

    /*insert(10);
	insert(20);
	insert(-10);
	insert(15);
	insert(17);
	insert(40);
	insert(50);
	insert(60);*/

	
    printf("Inorder traversal:\n");
    inorder(root);

    return 0;
}
