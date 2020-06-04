#include <iostream> 

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() { this->next = nullptr; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        this->head = nullptr;
    }

};

int main() {
    LinkedList lista;
    lista.append(12);
    return 0;
} 