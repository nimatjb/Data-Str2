#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class MinHeap {
private:
    Node* head;
    int size;

public:
    MinHeap() : head(nullptr), size(0) {}

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            Node* prev = nullptr;

            while (curr != nullptr && curr->value < newNode->value) {
                prev = curr;
                curr = curr->next;
            }

            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            }
            else {
                prev->next = newNode;
                newNode->next = curr;
            }
        }
        size++;
    }

    void Remove(int value) {
        if (head == nullptr) {
            cout << "empty" << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->value != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "not found" << endl;
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }

        delete curr;
        size--;
    }
};
