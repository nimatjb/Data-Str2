#include <iostream>
#include "1list.cpp"
using namespace std;

class queque
{
private:
	LinkedList stack;

	stack() {

		list = LinkedList();
		int size;
	}
public:
	Stack() {
		size = 0;
	}
	void push(int data) {
		stack.insertAtBegin(data);
		size++
	}
	int pop() {
		if (is_empty()) {
			return -1;
		}
		int data = stack.head->data;
		stack.removeNodeAtIndex(0);
		size--;
		return data;
	}
	int top() {
		if (is_empty()) {
			return -1;
		}
		return stack.head->data;
	}
	int size() {
		stack.sizeOfList();
	}
	bool is - empty() {
		return size = 0;
	}

}