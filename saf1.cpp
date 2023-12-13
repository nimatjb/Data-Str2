#include <iostream>
#include "1list.cpp"
using namespace std;

class queque
{
private:
	LinkedList queue;
	int size;
	queque() {
		list = LinkedList();
	}
	
public:
	Queue() {
		size = 0;
	}
	void enqeueqe(int data) {
		queue.insertAtEnd(data;
		size++;
	}
	int dequeue() {
		if (is - empty()) {
			return -1;
		}
		int data = queue.head->data;
		queue = queue.removeNodeAtIndex(0);
		size--;
		return data;
}
	int front() {
		if (is - empty()) {
			return -1;
		}
		return queue.head->data;
	}
	int size() {
		queue.sizeOfList();
	}
	bool is - empty() {
		return size = 0;
	}
	int display() {
		queue.printList();

	}