#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertAtIndex(int data, int index) {
        if (index < 0 || index > size) {
            return;
        }
        Node* new_node = new Node(data);
        if (size == 0) {
            head = new_node;
            tail = new_node;
            tail->next = head;
        }
        else if (index == 0) {
            new_node->next = head;
            head = new_node;
            tail->next = head;
        }
        else if (index == size) {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
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
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = data;
    }

    int RemoveNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
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
            data = head->data;
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        else if (index == size - 1) {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            data = tail->data;
            temp->next = head;
            delete tail;
            tail = temp;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* to_delete = temp->next;
            temp->next = temp->next->next;
            data = to_delete->data;
            delete to_delete;
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
    void Concatenate(CircularLinkedList* LinkedList) {
        if (size == 0) {
            head = LinkedList->head;
            tail = LinkedList->tail;
        }
        else if (LinkedList->size == 0) {
            return;
        }
        else {
            Node* temp = tail;
            tail = LinkedList->tail;
            temp->next = LinkedList->head;
            tail->next = head;
        }
        size += LinkedList->size;
    }
    void Invert() {
        if (size == 0) {
            return;
        }
        Node* prev_node = nullptr;
        Node* curr_node = head;
        Node* next_node = head->next;

        while (next_node != head) {
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
            next_node = next_node->next;
        }

        curr_node->next = prev_node;
        tail = head;
        head = curr_node;
    }
    void PrintList() {
        if (size == 0) {
            return;
        }
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
    }
};


