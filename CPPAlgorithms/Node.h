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

    void setNext(Node next) {
        this->next = next;
    }

    void setPrevious(Node previous) {
        this->previous = previous;
    }

    Node* getNext() {
        return this->next;
    }

    Node* getPrevious() {
        return this->previous;
    }

    T getValue() {
        return this->value;
    }

    std::string toString() {
        return "Node: " + std::to_string(value);
    }

    bool equals(T o) {
        Node e = (Node) o;
        T lhs = this->value;
        T rhs = e.value;

        return lhs == rhs;
    }
};

#endif //INC_263PROJECT_NODE_H
