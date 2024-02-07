#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

class LinkList
{

private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	/*1*/void InsertAtIndex(int data, int index) {

		if (index < 0 || index >= size) {
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

	/*2*/void InserAtEnd(int data) {
		InsertAtIndex(data, size);
	}

	/*3*/void InsertAtBegin(int data) {
		InsertAtIndex(data, size);
	}

	/*4*/void UpdateNode(int data, int index) {
		if (index < 0 || index >= size) {
			return;
		}

		Node* curr = head;

		for (int i = 0; i <= index - 1; i++) {
			curr = curr->next;
		}
		curr->data = data;
	}

	/*5*/void RemoveNodeAtIndex(int index, int data) {

		if (index < 0 || index >= size) {
			return;
		}

		if (index == 0) {
			Node* temp = head;
			data = temp->data;
			head = head->next;
			delete temp;
		}
		else {
			Node* curr = head;

			for (int i = 0; i <= index - 1; i++) {
				curr = curr->next;
			}

			Node* temp = curr->next;
			data = temp->data;
			curr->next = temp->next;
			delete temp;
		}
		size--;
	}

	/*6*/void RemoveNodeAtEnd() {
		if (size == 0) {
			return;
		}

		if (size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}

		Node* curr = head;
		while (curr->next != tail) {
			curr = curr->next;
		}

		delete tail;
		tail = curr;
		tail->next = nullptr;
		size--;
	}

	/*7*/ int removeNodeAtBegin() {
		if (size == 0) {
			return -1; // یا هر مقدار دیگری که بخواهید برای نشان دادن خالی بودن لیست استفاده کنید
		}

		Node* temp = head;
		int deletedData = temp->data;

		if (size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		else {
			head = head->next;
			delete temp;
			size--;
		}

		return deletedData;
	}

	/*8*/int sizeOfList() {
		return size;
	}


	/*9*/void printList() {
		Node* curr = head;

		while (curr != nullptr) {
			cout << curr->data;
			curr = curr->next;
		}
	}

	/*10*/void Concatenate(LinkList& list) {
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
	
	/*11*/void Invert() {
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
};












		  
