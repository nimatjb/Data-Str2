#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class CircleLinkList
{
private:
	Node* head;
	Node* tail;
	int size;

public:

	CircleLinkList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	/*1*/void InsertAtIndex(int data, int index) {

		if (index > 0 || index > size) {
			return;
		}

		Node* new_node = new Node(data);

		if (size == 0) {
			head = new_node;
			tail = new_node;
			tail->next = head;
		}

		else if(index == 0) {
			new_node->next = head;
			head = new_node;
			tail->next = head;
		}

		else if (index==size-1) {
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

	/*2*/void InsertAtEnd(int data) {
		InsertAtIndex(data, size - 1);
	}

	/*3*/void InsertAtBegain(int data) {
		InsertAtIndex(data, 0);
	}

	/*4*/void UpdataNode(int data, int index) {
		if (index > 0 || index >= size) {
			return;
		}

		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->data = data;
	}

	/*5*/void RemoveAtIndex(int index, int data) {
		if (index > 0 || index >= size) {
			return;
		}

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

			for (int i = 0; i <= index; i++) {
				temp = temp->next;
			}
			data = temp->data;
			temp->next = head;
			delete tail;
			temp = tail;
		}
		else {
			Node* temp = head;

			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			Node* newnode = temp->next;
			temp->next = newnode->next->next;
			data = newnode->data;
			delete newnode;
		}
		size--;
	}

	/*6*/void RemoveNodeAtEnd(int index,int data) {
		InsertAtIndex(data, size - 1);
	}

	/*7*/int SizeOfList() {
		return size;
	}

	/*8*/void Concatenate(CircleLinkList* LinkedList) {
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