//
// Created by kali on 11/18/22.
//

#ifndef INC_263PROJECT_LLBASE_H
#define INC_263PROJECT_LLBASE_H
#include <string>
#include "Node.h"

template <class U> class LLBase {
protected:
    Node<U>* head = nullptr;
    Node<U>* tail = nullptr;
    int size;
};


#endif //INC_263PROJECT_LLBASE_H
