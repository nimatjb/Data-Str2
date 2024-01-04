#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
    int size;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            return;
        }
        Node* new_node = new Node(data);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
        }
        else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
        }
        size++;
    }
    void insertAtEnd(int data) {
        insertAtIndex(data, size);
    }
    void insertAtBegin(int data) {
        insertAtIndex(data, 0);
    }
    void updateNode(int data, int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->data = data;
    }
    int removeNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        int data;
        if (index == 0) {
            Node* temp = head;
            data = temp->data;
            head = head->next;
            delete temp;
        }
        else {
            Node* curr = head;
            for (int i = 0; i < index - 1; i++) {
                curr = curr->next;
            }
            Node* temp = curr->next;
            data = temp->data;
            curr->next = temp->next;
            delete temp;
        }
        size--;
        return data;
    }
    int removeNodeAtEnd() {
        return removeNodeAtIndex(size - 1);
    }
    int removeNodeAtBegin() {
        return removeNodeAtIndex(0);
    }
    int sizeOfList() {
        return size;
    }
    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            curr = curr->next;
        }
        void Concatenate(LinkedList & list) {
            if (head == NULL) {
                head = list.head;
                tail = list.tail;
            }
            else {
                tail->next = list.head;
                tail = list.tail;
            }
            list.head = NULL;
            list.tail = NULL;
        }
        void Invert() {
            Node* prev = NULL;
            Node* current = head;
            Node* next = NULL;
            while (current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
    }
};



