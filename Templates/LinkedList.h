#pragma once
#include "Node.h"

template < class T >
class LinkedList {
	unsigned int length;
	Node<T>* head;
public:
	LinkedList();
	~LinkedList();
	//getters
	unsigned int getLength();
	Node<T>* getHead();
	T get(int pos);
	//setters
	void add(T val, int pos);
	void append(T val);
	bool remove(T val);
	bool seekanddestroy(int pos);
	bool contains(T val);
	
};

template<class T>
inline LinkedList<T>::LinkedList() {
	this->length = 0;
	this->head = nullptr;
}

template<class T>
inline LinkedList<T>::~LinkedList() {
	Node<T>* ptr = this->head;
	while (ptr != nullptr) {
		Node<T>* tmp = head;
		if (ptr->next != nullptr)
			ptr = ptr->next;
		delete tmp;
	}
}

template<class T>
inline unsigned int LinkedList<T>::getLength() {
	return this->len;
}

template<class T>
inline Node<T>* LinkedList<T>::getHead() {
	return this->head;
}

template<class T>
inline T LinkedList<T>::get(int pos) {
	if (pos < length) {
		Node<T>* ptr = head;
		while (pos-- != 0 && ptr->next != nullptr) {
			ptr = ptr->next;
		}
		return ptr->val;
	}
	throw;
}

template<class T>
inline void LinkedList<T>::add(T val, int pos) {
	if (pos < length) {
		Node<T>* ptr = head;
		//align one node before destination
		while (--pos > 0 && ptr->next != nullptr) {
			ptr = ptr.next;
		}
		//add element
		Node<T>* newnode = new Node<T>(val);
		if (ptr->next != nullptr) {
			newnode->next = ptr->next;
		}
		ptr->next = newnode;
	}
	else {
		throw;
	}
}

template<class T>
inline void LinkedList<T>::append(T val) {
	Node<T>* newnode = new Node<T>(val);
	newnode->next = head;
	this->head = newnode;
}

template<class T>
inline bool LinkedList<T>::remove(T val) {
	Node<T>* iter = this->head;
	//case first item is val
	if (iter->val == val) {
		if (this->head->next != nullptr) {
			Node<T>* tmp = this->head->next;
		}
		delete iter;
	}
	//case some other item may be vaL
	if (head != nullptr) {
		do {
			if (iter->next->val == val) {
				Node<T>* tmp = iter->next;
				if (iter->next->next != nullptr) {//case not last element
					iter->next = iter->next->next;
				}
				else {	//case last element
					iter->next = nullptr;
				}
				delete tmp;
			}
		} while (iter->next != nullptr);
	}
	//case item not found
	return true;
}

template<class T>
inline bool LinkedList<T>::seekanddestroy(int pos) {
	if (pos < length) {
		Node<T>* iter = head;
		while (pos-- > length) {
			iter = iter->next;
		}

		return 0;
	}
	else {
		return 1;
	}
}

template<class T>
inline bool LinkedList<T>::contains(T val) {
	Node<T>* ptr = head;
	if (ptr == nullptr)
		return false;
	
	while (ptr->next != nullptr) {
		if (ptr->val == val)
			return true;
	}
	return false;
}
