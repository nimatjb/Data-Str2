#include <iostream>
using namespace std;

class AVLTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;
    };

    Node* root;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->height = 1;
            return newNode;
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        else {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* removeRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = removeRecursive(root->left, value);
        }
        else if (value > root->data) {
            root->right = removeRecursive(root->right, value);
        }
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = removeRecursive(root->right, temp->data);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    /* Node* searchRecursive(Node* current, int value) {
         if (current == nullptr || current->data == value) {
             return current;
         }

         if (value < current->data) {
             return searchRecursive(current->left, value);
         }

         return searchRecursive(current->right, value);
     }

     void inOrderTraversal(Node* current) {
         if (current != nullptr) {
             inOrderTraversal(current->left);
             cout << current->data << " ";
             inOrderTraversal(current->right);
         }
     }*/

    public:
        AVLTree() {
            root = nullptr;
        }

        void insert(int value) {
            root = insertRecursive(root, value);
        }
        void remove(int value) {
            root = removeRecursive(root, value);
        }

        /* bool search(int value) {
             return searchRecursive(root, value) != nullptr;
         }

         void traverseInOrder() {
             inOrderTraversal(root);
         }*/
};
