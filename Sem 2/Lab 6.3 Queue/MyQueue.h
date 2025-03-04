#ifndef MYQUEUE_H
#define MYQUEUE_H

template<class T>
class Queue {
    class Node {
    public:
        T value = T(0);
        Node * next = nullptr;
        Node();
        Node(T value);
    };
    Node * first, * last;
    int size;
public:
    Queue();
    Queue(T value);
    ~Queue();

    void push_back(T value);
    T pop_front();
    T front();
    int get_size();
};

template<class T>
Queue<T>::Node::Node() = default;

template<class T>
Queue<T>::Node::Node(T value) {
    this->value = value;
}

template<class T>
Queue<T>::Queue() {
    this->size = 0;
}

template<class T>
Queue<T>::Queue(T value) {
    this->size = 1;
    Node * node = new Node(value);
    this->first = node;
    this->last = node;
}

template<class T>
Queue<T>::~Queue() {
    while (this->size > 0) {
        this->pop_front();
    }
}

template<class T>
void Queue<T>::push_back(T value) {
    Node * node = new Node(value);
    if (this->size == 0)
        this->first = node;
    else
        this->last->next = node;
    this->last = node;
    this->size += 1;
}

template<class T>
T Queue<T>::pop_front() {
    if (this->size == 0)
        return T(0);
    T value = this->first->value;
    Node * node = this->first;
    if (this->size == 1)
        this->last = nullptr;
    this->first = node->next;
    delete node;
    this->size -= 1;
    return value;
}

template<class T>
T Queue<T>::front() {
    if (this->size == 0)
        return T(0);
    return this->first->value;
}

template<class T>
int Queue<T>::get_size() {
    return this->size;
}


#endif //MYQUEUE_H
