#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;//قبلی

	Node(int data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;// انتها
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /*1*/void InsertAtIndex(int data, int index) {

        if (index < 0 || index > size) {
            return;
        }

        Node* newNode = new Node(data);

        if (size == 0) { // اگر لیست خالی باشد
            head = newNode; // سر لیست را به نود جدید اشاره کند
            tail = newNode; // انتهای لیست هم به نود جدید اشاره کند
        }

        else if (index == 0) { // اگر می‌خواهیم در مکان صفرم وارد کنیم
            newNode->next = head; // داده نود جدید را به نود سر قبلی وصل می‌کنیم
            head->prev = newNode; // و نود سر را به نود جدید وصل می‌کنیم
            head = newNode; // سر لیست را به نود جدید اشاره می‌کنیم
        }

        else if (index == size - 1) { // اگر می‌خواهیم در آخرین مکان وارد کنیم
            tail->next = newNode; // داده آخرین نود را به نود جدید وصل می‌کنیم
            newNode->prev = tail; // و نود جدید را به آخرین نود وصل می‌کنیم
            tail = newNode; // انتهای لیست را به نود جدید اشاره می‌کنیم
        }

        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next; // به نود قبل از نود مورد نظر می‌رسیم
            }
            newNode->next = current->next; // نود جدید را به نود بعد از نود فعلی وصل می‌کنیم
            newNode->prev = current; // و نود قبل از نود جدید را به نود فعلی وصل می‌کنیم
            current->next->prev = newNode; // نود بعد از نود فعلی را به نود جدید وصل می‌کنیم
            current->next = newNode; // و نود فعلی را به نود جدید و صل می‌کنیم
        }
        size++; // اندازه لیست را یک واحد افزایش می‌دهیم
    }

    /*2*/void InsertAtEnd(int data) {
        InsertAtIndex(data, size);
    }

    /*3*/void InsertAtBegin(int data) {
        InsertAtIndex(data, 0);
    }

    /*4*/void UpdataNode(int data, int index) {

        if (index<0 || index>size) {
            return;
        }
        Node* curr = head;
        for (int i = 0; i <= index; i++) {
            curr->next = curr;
        }
        curr->data = data;
    }

    /*5*/void RemoveNodeAtIndex(int index, int data) {

        if (index<0 || index>size) {
            return;
        }

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
            Node* curr = head;
            for (int i = 0; i <= index; i++) {
                curr = curr->next;
            }
            data = curr->data;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
        size--;
    }

    /*6*/void RemoveNodeAtEnd(int data) {
        RemoveNodeAtIndex(size - 1, data);
    }

    /*7*/int SizeOfList() {
        return size;
    }

    /*8*/void Concatenate(DoublyLinkedList* LinkedList) {
        if (LinkedList->size == 0) {
            return;
        }

        if (size == 0) {
            head = LinkedList->head; // سر و ته لیست ورودی را با سر و ته لیست قبلی جایگزین کنید.
            tail = LinkedList->tail;
        }
        else {
            tail->next = LinkedList->head; // بخش بعد از دمای لیست قبلی را به سر لیست ورودی متصل کنید.
            LinkedList->head->prev = tail; // بخش قبل از سر لیست ورودی را به دمای لیست قبلی متصل کنید.
            tail = LinkedList->tail; // دمای لیست ورودی را با دمای لیست قبلی جایگزین کنید.
        }

        size += LinkedList->size; // سایز لیست قبلی را با سایز لیست ورودی جمع کنید.
        LinkedList->head = nullptr; // هد و تیل لیست ورودی را تهی کنید.
        LinkedList->tail = nullptr;
        LinkedList->size = 0; // سایز لیست ورودی را صفر کنید.
    }

    /*9*/void Invert() {
        if (size == 0 || size == 1) {
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (tail != nullptr) {
            head = tail;
            tail = head->prev;
        }
    }

    /*10*/void PrintList() {
        if (size == 0) {
            return;
        }

        Node* curr = head;
        
        while (curr != nullptr) {
          cout<<curr->data;
            curr = curr->next;
        }
    }
};















