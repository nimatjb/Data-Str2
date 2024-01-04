#include <iostream>

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