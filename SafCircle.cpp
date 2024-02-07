#include <iostream>
using namespace std;
class Queue
{
private:
    int* arr;       // ارایه صف
    int cap;   // ظرفیت صف
    int size = 0;       // تعداد عناصر فعلی در صف
    int front = -1;      // ایندکس اول صف
    int rear = -1;       // ایندکس اخر صف

public:
    Queue(int cap) {

        this->cap = cap;
        this->arr = new int[cap];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }


    void Enqueue(int object) {
        if (IsFull()) {
            return;
        }
        else {
            if (IsEmpty()) {
                front = rear = 0;
            }
        }
        rear = (rear + 1) % cap;
        arr[rear] = object;
        size++;
    }

    int Dequeue() {
        if (IsEmpty()) {
            return -1;
        }
        int object = arr[front];
        front = (front + 1) % cap;
        size--;

        return object;
    }
int Peek() {
    if (IsEmpty()) {
        return -1;
    }

    return arr[front];
}
void ReverseQueue() {
    if (IsEmpty()) {
        return;
    }

    while (front != rear) {
        rear = (rear - 1 + capacity) % capacity;
        swap(arr[front], arr[rear]);
        front = (front + 1) % capacity;
        if (front == rear) {
            break;
        }
    }
}
};