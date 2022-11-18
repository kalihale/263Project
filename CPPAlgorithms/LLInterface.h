//
// Created by kali on 11/18/22.
//

#ifndef INC_263PROJECT_LLINTERFACE_H
#define INC_263PROJECT_LLINTERFACE_H
#include <string>

template <typename T> class LLInterface {
public:
    virtual int capacity() = 0;
    virtual bool isEmpty() = 0;
    virtual bool contains(T o) = 0;
    virtual T* toArray(T* array) = 0;
    virtual void add(T e) = 0;
    virtual void add(int index, T e) = 0;
    virtual bool remove(T o) = 0;
    virtual T remove(int index) = 0;
    virtual void clear() = 0;
    virtual T get(int index) = 0;
    virtual T set(int index, T e) = 0;
    virtual int indexOf(T o) = 0;
    virtual int lastIndexOf(T o) = 0;
    virtual void printForward() = 0;
    virtual void printReverse() = 0;
};

#endif //INC_263PROJECT_LLINTERFACE_H
