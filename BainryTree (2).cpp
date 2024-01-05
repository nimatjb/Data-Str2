#include <iostream>
#include<sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;


    void insertRecursive(Node* currentNode, int value) {
        if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node(value);
            }
            else {
                insertRecursive(currentNode->left, value);
            }
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node(value);
            }
            else {
                insertRecursive(currentNode->right, value);
            }
        }
    }

    Node* removeRecursive(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (value < currentNode->data) {
            currentNode->left = removeRecursive(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            currentNode->right = removeRecursive(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            Node* minimumNode = findMinimumNode(currentNode->right);
            currentNode->data = minimumNode->data;
            currentNode->right = removeRecursive(currentNode->right, minimumNode->data);
        }
        return currentNode;
    }

    Node* findMinimumNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }


    bool searchRecursive(Node* currentNode, int value) {
        if (currentNode == nullptr || currentNode->data == value) {
            return currentNode != nullptr;
        }

        if (value < currentNode->data) {
            return searchRecursive(currentNode->left, value);
        }
        else {
            return searchRecursive(currentNode->right, value);
        }
    }

    string preorderRecursive(Node* currentNode) {
        string result;
        if (currentNode != nullptr) {
            result += to_string(currentNode->data) + " ";
            result += preorderRecursive(currentNode->left);
            result += preorderRecursive(currentNode->right);
        }
        return result;
    }

    string inorderRecursive(Node* currentNode) {
        string result;
        if (currentNode != nullptr) {
            result += inorderRecursive(currentNode->left);
            result += to_string(currentNode->data) + " ";
            result += inorderRecursive(currentNode->right);
        }
        return result;
    }

    string postorderRecursive(Node* currentNode) {
        string result;
        if (currentNode != nullptr) {
            result += postorderRecursive(currentNode->left);
            result += postorderRecursive(currentNode->right);
            result += to_string(currentNode->data) + " ";
        }
        return result;
    }


public:
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insertRecursive(root, value);
        }
    }
    void remove(int value) {
        root = removeRecursive(root, value);
    }
    bool search(int value) {
        return searchRecursive(root, value);
    }
    string Preorder() {
        return preorderRecursive(root);
    }
    string Inorder() {
        return inorderRecursive(root);
    }
    string Postorder() {
        return postorderRecursive(root);
    }

};
