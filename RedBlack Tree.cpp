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

    void Insert(int n) {
        Node* newNode = new Node(n);
        if (root == nullptr) {
            newNode->color = COLOR::BLACK;
            root = newNode;
        }
        else {
            Node* temp = Search(n);

            if (temp->Item == n) {
                return;
            }

            newNode->parent = temp;

            if (n < temp->Item)
                temp->left = newNode;
            else
                temp->right = newNode;

            FixRedRed(newNode);
        }
    }

    void DeleteNode(Node* v) {
        Node* u = BSTreplace(v);

        bool uvBlack
            = ((u == nullptr || u->color == COLOR::BLACK)
                && (v->color == COLOR::BLACK));
        Node* parent = v->parent;

        if (u == nullptr) {
            if (v == root) {
                root = nullptr;
            }
            else {
                if (uvBlack) {
                    FixDoubleBlack(v);
                }
                else {
                    if (v->Sibling() != nullptr)
                        v->Sibling()->color = COLOR::RED;
                }

                if (v->IsOnLeft()) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            }
            return;
        }

        if (v->left == nullptr || v->right == nullptr) {
            if (v == root) {
                v->Item = u->Item;
                v->left = v->right = nullptr;
                DeleteNode(u);
            }
            else {
                if (v->IsOnLeft()) {
                    parent->left = u;
                }
                else {
                    parent->right = u;
                }
                u->parent = parent;

                if (uvBlack) {
                    FixDoubleBlack(u);
                }
                else {
                    u->color = COLOR::BLACK;
                }
            }
            return;
        }

        SwapValues(u, v);
        DeleteNode(u);
    }

    void DeleteByVal(int n) {
        if (root == nullptr)
            return;

        Node* v = Search(n);

        if (v->Item != n) {
            cout << "No node found to delete with value: " << n << endl;
            return;
        }

        DeleteNode(v);
    }

    void SwapColors(Node* x1, Node* x2) {
        COLOR temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    void SwapValues(Node* u, Node* v) {
        int temp = u->Item;
        u->Item = v->Item;
        v->Item = temp;
    }

    Node* Successor(Node* x) {
        Node* temp = x;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    Node* BSTreplace(Node* x) {
        if (x->left != nullptr && x->right != nullptr)
            return Successor(x->right);

        if (x->left == nullptr && x->right == nullptr)
            return nullptr;

        return x->left != nullptr ? x->left : x->right;
    }

    void FixDoubleBlack(Node* x) {
        if (x == root)
            return;

        Node* sibling = x->Sibling();
        Node* parent = x->parent;

        if (sibling == nullptr) {
            FixDoubleBlack(parent);
        }
        else {
            if (sibling->color == COLOR::RED) {
                parent->color = COLOR::RED;

                sibling->color = COLOR::BLACK;

                if (sibling->IsOnLeft()) {
                    RightRotate(parent);
                }
                else {
                    LeftRotate(parent);
                }
                FixDoubleBlack(x);
            }

            else {
                if (sibling->HRC()) {
                    if (sibling->left != nullptr && sibling->left->color == COLOR::RED) {
                        if (sibling->IsOnLeft()) {
                            sibling->left->color
                                = sibling->color;
                            sibling->color = parent->color;
                            RightRotate(parent);
                        }
                        else {
                            sibling->left->color
                                = parent->color;
                            RightRotate(sibling);
                            LeftRotate(parent);
                        }
                    }
                    else {
                        if (sibling->IsOnLeft()) {
                            sibling->right->color
                                = parent->color;
                            LeftRotate(sibling);
                            RightRotate(parent);
                        }
                        else {
                            sibling->right->color
                                = sibling->color;
                            sibling->color = parent->color;
                            LeftRotate(parent);
                        }
                    }
                    parent->color = COLOR::BLACK;
                }
                else {
                    sibling->color = COLOR::RED;
                    if (parent->color == COLOR::BLACK)
                        FixDoubleBlack(parent);
                    else
                        parent->color = COLOR::BLACK;
                }
            }
        }
    }
};

