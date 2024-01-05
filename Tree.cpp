#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    void Insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }

        if (value < node->value) {
            Insert(node->left, value);
        }
        else {
            Insert(node->right, value);
        }
    }

    void Remove(Node*& node, int value) {
        if (node == nullptr) {
            std::cout << "Value not found in tree." << std::endl;
            return;
        }

        if (value < node->value) {
            Remove(node->left, value);
        }
        else if (value > node->value) {
            Remove(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            }
            else {
                Node* minRight = FindMin(node->right);
                node->value = minRight->value;
                Remove(node->right, minRight->value);
            }
        }
    }
    void Insert(int value) {
        Insert(root, value);
    }

    void Remove(int value) {
        Remove(root, value);
    }
    Node* FindMin(Node* node) {
        if (node->left == nullptr) {
            return node;
        }
        else {
            return FindMin(node->left);
        }
    }
};
