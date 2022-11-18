//
// Created by kali on 11/17/22.
//

#ifndef INC_263PROJECT_DOUBLELINKEDLIST_H
#define INC_263PROJECT_DOUBLELINKEDLIST_H
#include "LLBase.h"
#include "LLInterface.h"
#include <stdexcept>

template <class T> class DoubleLinkedList : public LLBase<T>, LLInterface<T> {
public:
    int capacity() {
        int size = 0;
        Node<T>* ref = this->head;
        while(ref != nullptr) {
            ref = ref->getNext();
            size++;
        }
        return size;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    int size() {
        int size = 0;
        Node<T>* ptr = this->head;
        while(ptr != nullptr) {
            ptr = ptr->getNext();
            size++;
        }
        return size;
    }

    bool contains(T o) {
        Node<T>* ptr = this->head;
        while(ptr != nullptr) {
            if(ptr->getValue() == o) {
                return true;
            }
            else {
                ptr = ptr->getNext();
            }
        }
        return false;
    }

    T* toArray(T* array, int arrlen) {
        if(arrlen < size()) {
            throw std::invalid_argument("Array length less than list length");
        }
        Node<T> ptr = this->head;
        int index = 0;
        while(ptr != nullptr) {
            array[index] = ptr.getValue();
            ptr = ptr.getNext();
            index++;
        }
        return array;
    }

    void add(T e) {
        Node<T>* addNode = new Node<T>(e);
        if(this->head == nullptr) {
            addNode->setNext(nullptr);
            this->head = addNode;
        }
        else {
            Node<T>* ptr = this->tail;
            addNode->setNext(ptr->getNext());
            ptr->setNext(addNode);
            addNode->setPrevious(ptr);
        }
        this->tail = addNode;
        this->size++;
    }

    void add(int index, T e) {
        if(index < 0) {
            throw std::invalid_argument("Index < 0");
        }
        else if(this->head == nullptr) {
            add(e);
        }
        else if(index == 0) {
            Node<T>* addNode = new Node<T>(e);
            addNode->setNext(this->head);
            this->head = addNode;
            addNode->setPrevious(nullptr);
            addNode->getNext()->setPrevious(addNode);
        }
        else if(index < size()) {
            Node<T>* addNode = new Node<T>(e);
            Node<T> ptr = this->head;
            int i = 0;
            while(i < index - 1) {
                ptr = ptr.getNext();
                i++;
            }
            addNode->setNext(ptr.getNext());
            addNode->setPrevious(ptr.getPrevious());
            ptr.setNext(addNode);
            addNode->getNext()->setPrevious(addNode);
        }
        else {
            add(e);
        }
    }
};


#endif //INC_263PROJECT_DOUBLELINKEDLIST_H
