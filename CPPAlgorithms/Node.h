//
// Created by kali on 11/18/22.
//

#ifndef INC_263PROJECT_NODE_H
#define INC_263PROJECT_NODE_H
#include <string>

template <class T> class Node {
private:
    T value;
    Node<T>* next;
    Node<T>* previous;

public:
    Node(T value) {
        this->value = value;
        this->next;
        this->previous;
    }

    void setNext(Node<T>* next) {
        this->next = next;
    }

    void setPrevious(Node<T>* previous) {
        this->previous = previous;
    }

    Node<T>* getNext() {
        return this->next;
    }

    Node<T>* getPrevious() {
        return this->previous;
    }

    int getValue() {
        return this->value;
    }

    std::string toString() {
        return "Node: " + std::to_string(value);
    }

    bool equals(T o) {
        Node<T>* e = (Node<T>) o;
        T lhs = this->value;
        T rhs = e->value;

        return lhs == rhs;
    }
};

#endif //INC_263PROJECT_NODE_H
