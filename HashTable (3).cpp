﻿#include<iostream>
using namespace std;

class Node {
public:
    string key;
    int value; // مقدار گره
    Node* next; // گره بعدی

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr; // گره بعدی نبود
    }
};

class HashTable {
private:
    Node** table; // جدول هش
    int size; // تعداد عناصر
    int capacity; // ظرفیت

public:
    HashTable(int capacity) { // تعریف سازنده با ظرفیت
        this->capacity = capacity;
        this->size = 0;
        this->table = new Node * [capacity](); // ایجاد جدول هش با ظرفیت 
    }

    int HashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % capacity;
    }

    void Insert(string key, int value) {
        int index = HashFunction(key);
        Node* newNode = new Node(key, value); //ایجاد گره جدید
        if (table[index] == nullptr) {
            table[index] = newNode; // گره جدید
        }
        else {
            Node* temp = table[index]; // متغیر برای پیمایش
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode; // گذاشتن تهش جدید رو 
        }
        size++;
    }

    int Remove(string key) {
        int index = HashFunction(key);
        Node* prev = nullptr; // مقدار دادن به قبلی
        Node* curr = table[index]; // مقدار دادن به فعلی
        while (curr != nullptr) {
            if (curr->key == key) {
                int value = curr->value;
                if (prev == nullptr) {
                    table[index] = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr; // حذف  گره موردنظر
                size--;
                return value;
            }
            prev = curr;
            curr = curr->next; // گره بعدی برو
        }
        return -1;
    }

    int Search(string key) {
        int index = HashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
};

