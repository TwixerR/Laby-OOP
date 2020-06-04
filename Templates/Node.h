#pragma once
template < class T >
class Node {
public:
	T val;
	Node<T>* next;
	Node<T>();
	Node<T>(T arg);
};

template<class T>
inline Node<T>::Node() {
	this->next = nullptr;
}

template<class T>
inline Node<T>::Node(T arg) {
	this->next = nullptr;
	this->val = arg;
}