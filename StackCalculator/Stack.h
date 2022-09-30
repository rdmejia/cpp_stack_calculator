#pragma once

template <typename T>
class Stack
{
private:
    struct Node
    {
        T* value;
        Node* next;

        Node(T* value) {
            this->value = value;
            this->next = nullptr;
        }
    };

    int size;
    Node* head;

public:

    Stack() {
        this->head = nullptr;
        this->size = 0;
    }

    int get_size() {
        return this->size;
    }

    bool is_empty() {
        return this->head == nullptr;
    }

    void push(T* item) {
        Node* node = new Node(item);
        this->size++;

        if (this->is_empty()) {
            this->head = node;
            return;
        }

        node->next = this->head;
        this->head = node;
    }

    T* peek() {
        return this->head->value;
    }

    T* pop() {
        T* item = this->head->value;

        this->head = this->head->next;

        this->size--;

        return item;
    }
};

