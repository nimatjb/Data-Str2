#include <iostream>
#include "1list.cpp"
using namespace std;

class array
{
private:
	LinkedList list;
	
	array() {
		list = LinkedList();
	}
	int counter = 0;
public:
	void insert(int data,int index) {
		list.insertAtIndex(data,index);
	}
	void insertat(int data, int index) {
		list.insertAtIndex(data, index);
	}
	void removeat(int index) {
		list.removeNodeAtIndex(index);
	}
	void updata(int data,int index) {
		list.insertAtIndex(data,index);
	}
};


