#pragma once
#include "Stack.h"

//template<typename T>
//Stack<T>::Stack()
//{
//	this->head = nullptr;
//}
//
//template<typename T>
//void Stack<T>::push(T item) {
//	Node* node = { item, nullptr };
//
//	if (this->isEmpty()) {
//		this->head = node;
//		return;
//	}
//
//	node->next = head;
//	this->head = node;
//}
//
//template<typename T>
//T Stack<T>::peek()
//{
//	return this->head->value;
//}
//
//template<typename T>
//T Stack<T>::pop()
//{
//	T* value = this->head->value;
//
//	this->head = this->head->next;
//
//	return value;
//}
//
//template<typename T>
//bool Stack<T>::isEmpty()
//{
//	return this->head == nullptr;
//}
