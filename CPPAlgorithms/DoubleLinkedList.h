//
// Created by kali on 11/17/22.
//

#ifndef INC_263PROJECT_DOUBLELINKEDLIST_H
#define INC_263PROJECT_DOUBLELINKEDLIST_H
#include "LLBase.h"
#include "LLInterface.h"
#include <stdexcept>
#include <iostream>

template <class T> class DoubleLinkedList : public LLBase<T>, LLInterface<T> {
public:
    // ／(^ㅅ^)＼ Since there is no garbage collector, this is implemented differently than in Java
    // ／(^ㅅ^)＼ TODO
    void clear() {
        Node<T>* ptr;
        for(int i = 0; i < size(); ++i) {
            ptr = this->head;
            this->head = this->head.getNext();
            free(ptr);
        }
    }

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
        Node<T>* ptr = this->head;
        int index = 0;
        while(ptr != nullptr) {
            array[index] = ptr->getValue();
            ptr = ptr->getNext();
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
            Node<T>* ptr = this->head;
            int i = 0;
            while(i < index - 1) {
                ptr = ptr->getNext();
                i++;
            }
            addNode->setNext(ptr->getNext());
            addNode->setPrevious(ptr->getPrevious());
            ptr->setNext(addNode);
            addNode->getNext()->setPrevious(addNode);
        }
        else {
            add(e);
        }
    }

//    bool remove(T o) {
//        Node<T>* rm;
//        if(size() == 1 && this->head.getValue() == o) {
//            clear();
//            return true;
//        }
//        else if(this->head.getValue() == o) {
//            rm = this->head;
//            this->head = this->head.getNext();
//            this->head.setPrevious(nullptr);
//            free(rm);
//            return true;
//        }
//        else if(this->tail.getValue() == o) {
//            rm = this->tail;
//            this->tail = this->tail.getPrevious();
//            this->tail.setNext(nullptr);
//            free(rm);
//            return true;
//        }
//        else {
//            Node<T>* ptr = this->head.getNext();
//            while(ptr != nullptr) {
//                if(ptr->getValue() == o) {
//                    rm = ptr;
//                    ptr->getPrevious()->setNext(ptr->getNext());
//                    ptr->getNext()->setPrevious(ptr->getPrevious());
//                    free(rm);
//                    return true;
//                }
//                ptr = ptr->getNext();
//            }
//        }
//        return false;
//    }

    T remove(int index) {
        if(index < 0 || index >= size()) {
            throw std::invalid_argument("Invalid index");
        }
        else if(index == 0) {
            Node<T>* ptr = this->head;
            this->head = this->head.getNext();
            this->head.setPrevious(nullptr);
            T val = ptr->getValue();
            free(ptr);
            return val;
        }
        else if(index == size() - 1) {
            Node<T>* ptr = this->tail;
            this->tail = this->tail.getPrevious();
            this->tail.setNext(nullptr);
            T val = ptr->getValue();
            free(ptr);
            return val;
        }
        else {
            Node<T>* ptr = this->head.getNext();
            for(int i = 0; i < index; ++i) {
                ptr = ptr->getNext();
            }
            ptr->getPrevious()->setNext(ptr->getNext());
            ptr->getNext()->setPrevious(ptr->getPrevious());
            T val = ptr->getValue();
            free(ptr);
            return val;
        }
    }

    T get(int index) {
        if(index < 0 || index >= size()) {
            throw std::invalid_argument("Index out of bounds");
        }
        Node<T>* ptr = this->head;
        for(int i = 0; i < index; ++i) {
            ptr = ptr->getNext();
        }
        return ptr->getValue();
    }

    T set(int index, T e) {
        if(index < 0 || index >= size()) {
            throw std::invalid_argument("Index out of bounds");
        }
        Node<T>* ptr = this->head;
        for(int i = 0; i < index; ++i) {
            ptr = ptr->getNext();
        }
        Node<T>* newNode = new Node<T>(e);
        newNode->setNext(ptr->getNext());
        newNode->setPrevious(ptr->getPrevious());
        newNode->getNext()->setPrevious(newNode);
        newNode->getPrevious()->setNext(newNode);
        T val = ptr->getValue();
        free(ptr);
        return val;
    }

    int indexOf(T o) {
        Node<T>* ptr = this->head;
        int i = 0;
        while(ptr != nullptr) {
            if(ptr->getValue() == o) {
                return i;
            }
            ptr = ptr->getNext();
            i++;
        }
        return -1;
    }

    int lastIndexOf(T o) {
        Node<T>* ptr = this->tail;
        int i = size() - 1;
        while(ptr != nullptr) {
            if(ptr->getValue() == o) {
                return i;
            }
            ptr = ptr->getPrevious();
            i--;
        }
        return -1;
    }

    void printForward() {
        Node<T>* ptr = this->head;
        while(ptr != nullptr) {
            std::cout << ptr->toString() << std::endl;
            ptr = ptr->getNext();
        }
    }

    void printReverse() {
        Node<T>* ptr = this->tail;
        while(ptr != nullptr) {
            std::cout << ptr->toString() << std::endl;
            ptr = ptr->getPrevious();
        }
    };
};


#endif //INC_263PROJECT_DOUBLELINKEDLIST_H
