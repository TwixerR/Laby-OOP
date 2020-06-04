#pragma once
#include "Node.h"
template < class T >
class Stack {
public:
	Node<T>* head;
	Stack<T>();
	~Stack<T>();
	void push(T arg);
	T pop();
};

template<class T>
inline Stack<T>::Stack() {
	this->head = nullptr;
}

template<class T>
inline Stack<T>::~Stack() {
	if (head != nullptr) {
		Node<T>* tmp = head;
		if (head->next != nullptr) {
			head = head->next;
		}
		delete tmp;
	}
	this->head = nullptr;
}

template<class T>
inline void Stack<T>::push(T arg) {
	Node<T> newnode(arg);
	newnode.next = this->head;
	this->head = &newnode;
}

template<class T>
inline T Stack<T>::pop() {
	T ret = this->head->val;
	Node<T>* tmp = this->head;
	if (this->head->next != nullptr) {
		head = head->next;
	}
	delete tmp;
	return ret;
}
