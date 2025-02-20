#ifndef MYDEQUE_H
#define MYDEQUE_H
#include <iostream>

template<class T>
class MyDeque {
    class Node {
    public:
        T value;
        Node * prev = nullptr;
        Node * next = nullptr;

        Node();
        Node(T value);
    };

    Node * first = nullptr;
    Node * last = nullptr;
    int size = 0;

public:
    MyDeque();
    MyDeque(T value);
    MyDeque(T * value, int size);
    ~MyDeque();

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();
    bool empty();
    int get_size();
    T front();
    T back();

    void print();
};

template<class T>
MyDeque<T>::Node::Node() {
    this->value = NULL;
}

template<class T>
MyDeque<T>::Node::Node(T value) {
    this->value = value;
}

template<class T>
MyDeque<T>::MyDeque() {}

template<class T>
MyDeque<T>::MyDeque(T value) {
    Node * node = new Node(value);
    this->first = node;
    this->last = node;
    this->size = 1;
}

template<class T>
MyDeque<T>::MyDeque(T * value, int size) : MyDeque(value) {
    for (int i = 1; i < size; i++) {
        this->push_front(value[i]);
    }
    this->size = size;
}

template<class T>
MyDeque<T>::~MyDeque() {
    for (int i = 0; i < this->size; i++) {
        this->pop_front();
    }
}

template<class T>
void MyDeque<T>::push_front(T value) {
    Node * node = new Node(value);
    if (this->first == nullptr)
        this->last = node;
    else {
        this->first->prev = node;
        node->next = this->first;
    }
    this->first = node;
    this->size += 1;
}

template<class T>
void MyDeque<T>::push_back(T value) {
    Node * node = new Node(value);
    if (this->last == nullptr)
        this->first = node;
    else {
        this->last->next = node;
        node->prev = this->last;
    }
    this->last = node;
    this->size += 1;
}

template<class T>
T MyDeque<T>::pop_front() {
    if (this->size > 0) {
        T value = this->first->value;
        Node * node = this->first;
        this->first = node->next;
        if (this->size > 1)
            this->first->prev = nullptr;
        else // если осталась одна нода то надо обнулить полностью дэк
            this->first = nullptr;
        delete node;
        this->size -= 1;
        return value;
    }
    return T(0);
}


template<class T>
T MyDeque<T>::pop_back() {
    if (this->size > 0) {
        T value = this->last->value;
        Node * node = this->last;
        this->last = node->prev;
        if (this->size > 1)
            this->last->next = nullptr;
        else // если осталась одна нода то надо обнулить полностью дэк
            this->last = nullptr;
        delete node;
        this->size -= 1;
        return value;
    }
    return T(0);
}

template<class T>
bool MyDeque<T>::empty() {
    return this->size == 0;
}

template<class T>
int MyDeque<T>::get_size() {
    return this->size;
}

template<class T>
T MyDeque<T>::front() {
    if (this->empty()) {
        return T(0);
    }
    return this->first->value;
}

template<class T>
T MyDeque<T>::back() {
    if (this->empty()) {
        return T(0);
    }
    return this->last->value;
}

template<class T>
void MyDeque<T>::print() {
    Node * pointer = this->first;
    for(int i = 0; i < this->size; i ++) {
        std::cout << pointer->value << '\n';
        pointer = pointer->next;
    }
}


#endif //MYDEQUE_H
