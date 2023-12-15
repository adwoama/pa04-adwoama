//
//  Iterator.h
//  Class Template "Iterator"
//
//  used Iterator class from followiing link
// https://www.out4mind.com/en/doubly-linked-list-with-class-templates-part-i/

#ifndef Iterator_h
#define Iterator_h

#pragma once
#include <stdlib.h>
#include "DSNode.h"

template <class T>
class Iterator {
private:
    // Pointer for the actual node being iterated
    DSNode<T> *actualNode;
    
public:
    // The iterator constructor shall receive a node
    // It can receive the head or the tail of the list in order to iterate all the nodes
    Iterator(DSNode<T> *node = nullptr) : actualNode(node) {}
    ~Iterator() {
        if (actualNode==nullptr) {
            actualNode = nullptr;
        }
    }
    // Returns the next node or NULL after reaching the end
    DSNode<T> *nextNode() {
        if (actualNode==nullptr) {
            return nullptr;
        }
        actualNode = actualNode->getNext();
        return actualNode;
    }
    // Return the previous node or NULL after reaching the start
    DSNode<T> *previousNode() {
        if (actualNode==nullptr) {
            return nullptr;
        }
        actualNode = actualNode->getPrev();
        return actualNode;
    }
    DSNode<T> *currentNode() {
        return actualNode;
    }

    
};

#endif
