#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            return;
        }
        Node* newNode = new Node(data);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        }
        else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (index == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
        size++;
    }
    void InsertAtEnd(int data) {
        InsertAtIndex(data, size);
    }
    void InsertAtBegin(int data) {
        InsertAtIndex(data, 0);
    }
    void UpdateNode(int data, int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }
    int RemoveNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        int data;
        if (size == 1) {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0) {
            Node* temp = head;
            data = temp->data;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        else if (index == size - 1) {
            Node* temp = tail;
            data = temp->data;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            data = current->data;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
        return data;
    }
    int RemoveNodeAtEnd() {
        return RemoveNodeAtIndex(size - 1);
    }
    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }
    int SizeOfList() {
        return size;
    }
    void Concatenate(DoublyLinkedList* LinkedList) {
        if (LinkedList->size == 0) {
            return;
        }
        if (size == 0) {
            head = LinkedList->head;
            tail = LinkedList->tail;
        }
        else {
            tail->next = LinkedList->head;
            LinkedList->head->prev = tail;
            tail = LinkedList->tail;
        }
        size += LinkedList->size;
        LinkedList->head = nullptr;
        LinkedList->tail = nullptr;
        LinkedList->size = 0;
    }
    void Invert() {
        if (size == 0 || size == 1) {
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (tail != nullptr) {
            head = tail;
            tail = head->prev;
        }
    }
    void PrintList() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};




