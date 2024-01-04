#include <iostream>
using namespace std;

enum COLOR { RED, BLACK };

class Node {
public:
    int Item;
    COLOR color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        this->Item = val;
        parent = left = right = nullptr;

        color = COLOR::RED;
    }

    Node* Uncle() {
        if (parent == nullptr || parent->parent == nullptr)
            return nullptr;

        if (IsOnLeft())
            return parent->parent->right;
        else
            return parent->parent->left;
    }

    bool IsOnLeft() { return this == parent->left; }

    Node* Sibling() {
        if (parent == nullptr)
            return nullptr;

        if (IsOnLeft())
            return parent->right;

        return parent->left;
    }

    void MoveDown(Node* nParent) {
        if (parent != nullptr) {
            if (IsOnLeft())
                parent->left = nParent;
            else
                parent->right = nParent;
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool HRC() {
        return (left != nullptr && left->color == COLOR::RED)
            || (right != nullptr && right->color == COLOR::RED);
    }
};

class RBTree {
    Node* root;

public:
    Node* GetRoot() { return root; }

    void LeftRotate(Node* x) {
        Node* nParent = x->right;

        if (x == root)
            root = nParent;

        x->MoveDown(nParent);

        x->right = nParent->left;

        if (nParent->left != nullptr)
            nParent->left->parent = x;

        nParent->left = x;
    }

    void RightRotate(Node* x) {
        Node* nParent = x->left;

        if (x == root)
            root = nParent;

        x->MoveDown(nParent);

        x->left = nParent->right;

        if (nParent->right != nullptr)
            nParent->right->parent = x;

        nParent->right = x;
    }

    Node* Search(int n) {
        Node* temp = root;
        while (temp != nullptr) {
            if (n < temp->Item) {
                if (temp->left == nullptr)
                    break;
                else
                    temp = temp->left;
            }
            else if (n == temp->Item) {
                break;
            }
            else {
                if (temp->right == nullptr)
                    break;
                else
                    temp = temp->right;
            }
        }

        return temp;
    }

    void FixRedRed(Node* x) {
        if (x == root) {
            x->color = COLOR::BLACK;
            return;
        }

        Node* parent = x->parent;
        Node* grandparent = parent->parent;
        Node* uncle = x->Uncle();

        if (parent->color != COLOR::BLACK) {
            if (uncle != nullptr && uncle->color == COLOR::RED) {
                parent->color = COLOR::BLACK;
                uncle->color = COLOR::BLACK;
                grandparent->color = COLOR::RED;
                FixRedRed(grandparent);
            }
            else {
                if (parent->IsOnLeft()) {
                    if (x->IsOnLeft()) {
                        SwapColors(parent, grandparent);
                    }
                    else {
                        LeftRotate(parent);
                        SwapColors(x, grandparent);
                    }
                    RightRotate(grandparent);
                }
                else {
                    if (x->IsOnLeft()) {
                        RightRotate(parent);
                        SwapColors(x, grandparent);
                    }
                    else {
                        SwapColors(parent, grandparent);
                    }

                    LeftRotate(grandparent);
                }
            }
        }
    }
