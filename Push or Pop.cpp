#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int top;
    int items[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool is_empty() {
        return (top == -1);
    }

    int push(int item) {
        if (is_empty()) {
            return -1;
        }
        else {
            if (top < MAX_SIZE - 1) {
                items[++top] = item;
                return top + 1;
            }
        }
    }

    int pop() {
        if (is_empty()) {
            return -1;
        }
        else {
            if (top > -1) {
                item[top--] = -1;
                return top + 1;
        }
    }

    int peek() {
        if (is_empty()) {
            return -1;
        }
        else {
            return items[top];
        }
    }
};


