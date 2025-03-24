#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

template<class T>
class MyList {
    struct Node {
        T value;
        Node * next = nullptr;
        Node * prev = nullptr;

        explicit Node(T value);
    };
    int size = 0;
    Node * first, * last;
public:
    MyList();
    explicit MyList(T value);
    MyList(const MyList& other);
    ~MyList();

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();
    bool insert(int pos, T value);
    void sort();

    int get_size() const;
    T& at(int pos);
    int find(T value);
    void print();
};

template<class T>
MyList<T>::Node::Node(T value) {
    this->value = value;
}

template<class T>
MyList<T>::MyList() : first(nullptr), last(nullptr) {}

template<class T>
MyList<T>::MyList(T value) {
    Node * node = new Node(value);
    this->first = this->last = node;
    ++this->size;
}

template<class T>
MyList<T>::MyList(const MyList &other) {
    Node * point = other.first;
    for (int i = 0; i < other.size; i++) {
        this->push_back(point->value);
        point = point->next;
    }
}

template<class T>
MyList<T>::~MyList() {
    while (this->size > 0) {
        this->pop_back();
    }

}

template<class T>
void MyList<T>::push_front(T value) {
    Node * node = new Node(value);
    if (this->size == 0)
        this->last = node;
    else {
        node->next = this->first;
        this->first->prev = node;
    }
    this->first = node;
    ++this->size;
}

template<class T>
void MyList<T>::push_back(T value) {
    Node * node = new Node(value);
    if (this->size == 0)
        this->first = node;
    else {
        node->prev = this->last;
        this->last->next = node;
    }
    this->last = node;
    ++this->size;
}

template<class T>
T MyList<T>::pop_front() {
    if (this->size == 0)
        throw std::out_of_range("pop_front called on empty list");
    T value = this->first->value;
    Node * node = this->first;
    if (this->size > 1) {
        this->first = node->next;
        this->first->prev = nullptr;
    }
    else {
        this->first = this->last = nullptr;
    }
    delete node;
    --this->size;
    return value;
}

template<class T>
T MyList<T>::pop_back() {
    if (this->size == 0)
        throw std::out_of_range("pop_back called on empty list");
    T value = this->last->value;
    Node * node = this->last;
    if (this->size > 1) {
        this->last = node->prev;
        this->last->next = nullptr;
    }
    else {
        this->first = this->last = nullptr;
    }
    delete node;

    --this->size;
    return value;
}

template<class T>
bool MyList<T>::insert(int pos, T value) {
    if (pos > this->size)
        return false;
    Node * node = new Node(value);
    if (pos <= this->size/2) {
        Node * point = this->first;
        for (int i = 0; i < this->size; i++) {
            if (i == pos) {
                if (i > 0) {
                    point->prev->next = node;
                    node->prev = point->prev;
                } else
                    this->first = node;
                point->prev = node;
                node->next = point;
                ++this->size;
                return true;
            }
            point = point->next;
        }
    }
    else {
        Node * point = this->last;
        for (int i = this->size; i > 0; i--) {
            if (i == pos) {
                if (i < this->size) {
                    point->next->prev = node;
                    node->next = point->next;
                } else
                    this->last = node;
                point->next = node;
                node->prev = point;
                ++this->size;
                return true;
            }
            point = point->prev;
        }
    }
    return false;
}

template<class T>
void MyList<T>::sort() {
    if (this->size < 2) return;
    for (int i = 0; i < this->size; i++) {
        Node * point = this->first;
        for (int j = 0; j < this->size - 1; j++) {
            if(point->value > point->next->value)
                std::swap(point->value, point->next->value);
            point = point->next;
        }
    }

}

template<class T>
int MyList<T>::get_size() const {
    return this->size;
}

template<class T>
T& MyList<T>::at(int pos) {
    if (pos > this->size)
        throw std::out_of_range("Index out of range");
    Node * point = this->first;
    for (int i = 0; i < pos; i++)
        point = point->next;
    return point->value;

}

template<class T>
int MyList<T>::find(T value) {
    Node * point = this->first;
    for (int i = 0; i < this->size; i++) {
        if (point->value == value)
            return i;
        point = point->next;
    }
    return -1;
}

template<class T>
void MyList<T>::print() {
    Node * point = this->first;
    for (int i = 0; i < this->size; i++) {
        std::cout << point->value << "\n";
        point = point->next;
    }
}

#endif //LIST_H
