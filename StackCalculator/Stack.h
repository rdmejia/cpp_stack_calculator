#pragma once

template <typename T>
class Stack
{
private:
	struct Node {
		T value;
		Node* next;

		Node(T value) {
			this->value = value;
			this->next = nullptr;
		}
	};

	Node* head;
	int size;

public:
	Stack() {
		this->head = nullptr;
		this->size = 0;
	}

	int getSize() {
		return this->size;
	}

	void push(T item) {
		if (this->isEmpty()) {
			this->head = new Node(item);
		} else {
			Node* node = new Node(item);
			node->next = this->head;
			this->head = node;
		}

		this->size++;
	}

	T peek() {
		return this->head->value;
	}

	T pop() {
		T item = this->head->value;

		this->head = this->head->next;

		this->size--;

		return item;
	}

	bool isEmpty() {
		return this->head == nullptr;
	}
};

