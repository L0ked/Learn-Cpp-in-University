#include "MyStack.h"
#include <iostream>

using std::cout;

template<class T>
Node<T>::Node() {
    this->value = NULL;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(T value, Node * next) {
    this->value = value;
    this->next = next;
}

template<class T>
MyStack<T>::MyStack() {
    this->root = new Node<T>();
    this->size = 0;
}

template<class T>
MyStack<T>::MyStack(T value) {
    this->size = 1;
    Node<T> * node = new Node<T>();
    this->root = new Node<T>(value, node);
}

template<class T>
MyStack<T>::~MyStack() {
    this->clear();
    delete this->root;
}

template<class T>
void MyStack<T>::push(T value) {
    this->root = new Node<T>(value, this->root);
    this->size += 1;
}

template<class T>
T MyStack<T>::pop() {
    T value = this->root->value;
    this->del();
    return value;
}

template<class T>
T MyStack<T>::top() {
    return this->root->value;
}

template<class T>
void MyStack<T>::print() {
    Node<T> * point = this->root;
    for (int i = this->size; i > 0; i--) {
        cout << point->value << "\n";
        point = point->next;
    }
}

template<class T>
bool MyStack<T>::empty() {
    return this->size == 0;
}

template<class T>
void MyStack<T>::clear() {
    while (this->size > 0) {
        this->del();
    }
}

template<class T>
void MyStack<T>::del() {
    Node<T> * a = this->root;
    this->root = a->next;
    delete a;
    this->size -= 1;
}

// template class MyStack<int>;
// template class MyStack<char>;