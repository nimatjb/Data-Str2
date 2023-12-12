
    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }

    int SizeOfList() {
        return size;
    }
    void Concatenate(CircularLinkedList* LinkedList) {
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


