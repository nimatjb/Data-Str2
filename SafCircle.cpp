#include <iostream>
using namespace std;
class Queue
{
private:
    int* arr;       // Ø¢Ø±Ø§ÛŒÙ‡â€ŒÛŒ Ø¯Ø§Ø¯Ù‡â€ŒÙ‡Ø§
    int capacity;   // Ø¸Ø±ÙÛŒØª ØµÙ
    int size = 0;       // ØªØ¹Ø¯Ø§Ø¯ Ø¹Ù†Ø§ØµØ± ÙØ¹Ù„ÛŒ Ø¯Ø± ØµÙ
    int front = -1;      // Ø§ÛŒÙ†Ø¯Ú©Ø³ Ø¹Ù†ØµØ± Ø§Ø¨ØªØ¯Ø§ÛŒ ØµÙ
    int rear = -1;       // Ø§ÛŒÙ†Ø¯Ú©Ø³ Ø¹Ù†ØµØ± Ø§Ù†ØªÙ‡Ø§ÛŒ ØµÙ

public:
    Queue(int capacity) {

        this->capacity = capacity;
        this->arr = new int[capacity];
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
        rear = (rear + 1) % capacity;
        arr[rear] = object;
        size++;
    }

    int Dequeue() {
        if (IsEmpty()) {
            return -1;
        }
        int object = arr[front];
        front = (front + 1) % capacity;
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