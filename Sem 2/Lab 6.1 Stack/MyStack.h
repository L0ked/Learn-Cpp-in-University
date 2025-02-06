#ifndef MYSTACK_LIBRARY_H
#define MYSTACK_LIBRARY_H


template <class T>
class Node {
public:
    T value;
    Node * next;
    Node();
    Node(T value, Node * next);
};

template <class T>
class MyStack {
    Node<T> *root;
    int size;
public:
    MyStack();
    explicit MyStack(T value);
    ~MyStack();
    void push(T value);
    T pop();
    T top();
    void print();
    bool empty();
    void clear();
private:
    void del();
};


#endif //MYSTACK_LIBRARY_H
