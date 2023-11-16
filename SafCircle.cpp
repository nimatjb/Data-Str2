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

    int IsEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool IsFull() {
        return size == cap;
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

    int* reversedArr = new int[cap];
    int index = 0;

    // از انتهای صف به ابتدا آرایه‌ی برعکس را پر می‌کنیم
    for (int i = rear; i >= front; i--) {
        reversedArr[index++] = arr[i];
    }

    // جایگزین کردن آرایه‌ی اصلی با آرایه‌ی برعکس شده
    delete[] arr;
    arr = reversedArr;

    // به روزرسانی ایندکس‌ها
    front = 0;
    rear = size - 1;



};