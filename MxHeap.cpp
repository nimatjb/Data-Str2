#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class MaxHeap {
private:
    Node* head;
    int size;

public:
    MaxHeap() : head(nullptr), size(0) {}

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            Node* prev = nullptr;

            while (curr != nullptr && curr->value > newNode->value) {
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