#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

#ifndef STACK_H
#define STACK_H

template<typename T>
class node {
public:
    node *next = NULL;
    T val;

    node(T v);
};

template<typename T>
class stack {
private:
    int len = 0;

public:
    node<T> *head = NULL;

    void push(T val);

    T pop();

    int length();
};

template<typename T>
ostream &operator<<(ostream &os, stack<T> &st);

template<typename T>
node<T>::node(T v) {
    val = v;
    next = NULL;
}

template<typename T>
void stack<T>::push(T val) {
    node<T> *n = new node<T>(val);
    n->val = val;
    n->next = head;
    head = n;
    len++;
}

template<typename T>
T stack<T>::pop() {
    if (head == NULL) {
//        cout << "Jopa";
        throw std::out_of_range("Stack is empty");
    }
    len--;
    node<T> *t = head;
    T val = t->val;
    head = head->next;
    // delete(t);
    return val;
}

template<typename T>
int stack<T>::length() {
    return len;
}

template<typename T>
ostream &operator<<(ostream &os, stack<T> &st) {
    if (st.length() <= 0) {
        os << "Empty\n";
    } else {
        node<T> *t = st.head;

//        cout << "stack\n len: " << st.length() << endl;
        while (t != NULL) {
            os << "  " << t->val << endl;
            t = t->next;
        }

    }
    return os;
}

#endif