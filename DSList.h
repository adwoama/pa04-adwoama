//
// Created by robot on 3/23/2021.
//

#ifndef PA04_AMAZING_DSLIST_H
#define PA04_AMAZING_DSLIST_H
#include "DSNode.h"
#include "Iterator.h"

#include <iostream>

using namespace std;

template<class T>
class DSList {
private:

    DSNode<T>* head;
    DSNode<T>* tail;
    Iterator<T>* iter;

    int size;
public:
    //constructors & destructors
    DSList();
    DSList(DSList<T>& val);
    ~DSList();
    //operators
    DSList<T>& operator = (const DSList<T>& val);
    //accessors
    DSNode<T>* front();
    DSNode<T>* back();
    DSNode<T>* at(int loc);
    int find(T val);//TODO add implementaion
    int getSize();
    bool isEmpty();
    //iterators
    Iterator<T>* getIteratorAtHead();
    Iterator<T>* getIteratorAtTail();
    DSNode<T>* iterNext();
    DSNode<T>* iterPrev();
    DSNode<T>* iterCurrent();
    void resetIter();

    //mutators
    void insert_front(T val);
    void insert_front(DSNode<T>* val);
    void insert_after(DSNode<T>* prevNode, T& val);
    void push_back(const T& val);
    void push_back(DSNode<T>* val);
    void deleteAt(int loc);
    bool remove(DSNode<T>* r);
    void clear();
    DSNode<T> pop_back();
    DSNode<T> pop_front();
};



template<class T>
DSList<T>::DSList(){
    head = new DSNode<T>();
    tail = new DSNode<T>();
    iter = new Iterator<T>(head);
    size = 0;

}//default construcotr
template<class T>
DSList<T>::DSList(DSList<T>& val){
    DSNode<T>* current = val.head;
    clear();
    head = new DSNode<T>;
    tail = new DSNode<T>;
    iter = new Iterator<T>(head);
    while(current->getNext() != nullptr){
        push_back(current->getData());
        current = current->getNext();
    }
}//copy constructor
template<class T>
DSList<T>::~DSList(){
    clear();
    delete head;
    delete tail;
}//destructor
template<class T>
bool DSList<T>::isEmpty(){
    //cout << "head: " << head-> getNext() << endl;
    return head->getNext()== nullptr;
}
//operators
template<class T>
DSList<T>& DSList<T>::operator= (const DSList<T>& val){
    if(head != val.head) {
        clear();
        head = new DSNode<T>;
        tail = new DSNode<T>;
        if (val.size != 0) {
            DSNode<T> *current = val.head->getNext();
            push_back(current->getData());
            while(current->getNext() != nullptr){
                current = current->getNext();
                push_back(current->getData());
            };
        }
    }//don't self assign

    return *this;
}//operator =
//accessors
/**
 *
 * @tparam T datatype of nodes
 * @return pointer to head of doubly linked list
 */
template<class T>
DSNode<T>* DSList<T>::front(){
    return head->getNext();
}//front()
/**
 *
 * @tparam T datatype of nodes
 * @return pointer to tail of doubly linked list
 */
template<class T>
DSNode<T>* DSList<T>::back(){
    return tail->getPrev();
}//back()
/**
 *
 * @tparam T datatype of list nodes
 * @param loc location of node to access
 * @return node at loc
 */
template<class T>
DSNode<T>* DSList<T>::at(int loc){
    DSNode<T>* current = head->getNext();

    for(int i = 0; i<loc && i<size; i++){

        current = current->getNext();
    }

    return current;
}//at(int loc)
/**
 *
 * @param val
 * @return
 */
template<class T>
int DSList<T>::find(T val){
Iterator<T>* i = this->getIteratorAtHead();
DSNode<T>* search;
int spot = 0;
while((search = i->nextNode())!= nullptr){
    if(search->getData() == val){
        return spot;
    }
    spot++;
}

return -1;
}
template<class T>
int DSList<T>::getSize(){
    return size;
}//getSize
template<class T>
Iterator<T>* DSList<T>::getIteratorAtHead() {
    Iterator<T> *i = new Iterator<T>(head);
    return i;
}
template<class T>
// Returns a new iterator initiated at the tail
Iterator<T>* DSList<T>::getIteratorAtTail() {
    Iterator<T> *i = new Iterator<T>(tail);
    return i;
}
template<class T>
DSNode<T>* DSList<T>::iterNext(){
    return iter->nextNode();
}
template<class T>
DSNode<T>* DSList<T>::iterPrev(){
    return iter->previousNode();
}
template<class T>
DSNode<T>* DSList<T>::iterCurrent(){
    return iter->currentNode();
}
template<class T>
void DSList<T>::resetIter(){
    iter = getIteratorAtHead();
}
//mutators
/**
 * Inserts a new node before the head of the list
 * @tparam T datatype of list nodes
 * @param val data to be added to list
 */
template<class T>
void DSList<T>::insert_front(T val){
    if (isEmpty()) {
        // If the list is empty, inserts a "first" node
        DSNode<T> *newNode = new DSNode<T>(val);
        head->setNext(newNode);
        tail->setPrev(newNode) ;
        iter->nextNode();
    }
    else {
        // Otherwise inserts a new "first" node
        DSNode<T> *actualFirst = head->getNext();
        // The new node shall have its pointer "next" pointing to the old first node...
        // ... and its pointer "previous" set to NULL as this one will became the new first node
        DSNode<T> *newNode = new DSNode<T>(val, actualFirst);
        // The old first node shall have its pointer "previous" pointing to the new first node
        actualFirst->setPrev(newNode);
        // Finally, the head shall point to the new node
        head->setNext(newNode);
    }
    size++;
}//insert_front
/**
 *
 * @param val
 */
template<class T>
void DSList<T>::insert_front(DSNode<T>* val){
    //TODO
    size++;
}//insert_front
template<class T>
/**
 * Inserts a new node into the list after a known node
 * @tparam T datatype of list nodes
 * @param prevNode node that we want to insert after
 * @param val data to be added to list
 */
void DSList<T>::insert_after(DSNode<T>* prevNode, T& val){
    if((prevNode == tail)|| size == 0){
        push_back(val);
    }
    else {
        DSNode<T> *toAdd = new DSNode<T>;
        toAdd->setData(val);

        toAdd->setPrev(prevNode);
        toAdd->setNext(prevNode->getNext());
        prevNode->setNext(toAdd);
        (toAdd->getNext())->setPrev(toAdd);
        size++;
    }

    /*
    // Search the "reference" node from the head
    DSNode<T> *searchRef = head->getNext();
    while (searchRef!= nullptr) {
        if (searchRef==prevNode) {
            // If the node is found, interrupt the loop
            break;
        }
        searchRef = searchRef->getNext();
    }

    if (searchRef== nullptr) {
        // If the "reference" node was not found, returns false
        return false;
    }
    else {
        // If it was found, declares a pointer to the position that follows the reference node
        DSNode<T> *afterRef = searchRef->getNext();
        // The new node shall have its pointer "next" pointing to the node that follows the reference node...
        // ... and its pointer "previous" pointing to the reference node (insert after)
        DSNode<T> *newNode = new DSNode<T>(val, afterRef, searchRef);

        if (afterRef== nullptr) {
            // If the pointer to the next node is NULL we are inserting at the tail of the list
            tail->setPrev(newNode);
        }
        else {
            // Otherwise, we change its pointer "previous" to the new node
            afterRef->setPrev(newNode);
        }
        // And for the reference node, we change its pointer "next" to the new node
        searchRef->setNext(newNode);
        return true;
    }
     */
}
/**
 * Inserts a new node at the end of the list
 * @tparam T datatype of list nodes
 * @param val value to append
 */
template<class T>
void DSList<T>::push_back(const T& val){
    if (isEmpty()) {
        //cout<<"empty"<< endl;
        // If the list is empty, inserts a "first" node
        DSNode<T> *newNode = new DSNode<T>(val);
        head->setNext(newNode);
        tail->setPrev(newNode);
        newNode->setPrev(head);
        newNode->setNext(tail);
        iter = new Iterator<T>(newNode);
        //delete newNode;
    }
    else {
        // Otherwise inserts a new "last" node
        DSNode<T> *actualLast = tail->getPrev();
        // The new node shall have its pointer "next" set to NULL as it will became the new last node...
        // ... and its pointer "previous" pointing to the old last node
        DSNode<T> *newNode = new DSNode<T>(val, tail, actualLast);
        // The old last node shall have its pointer "next" pointing to the new last node
        actualLast->setNext(newNode);
        // Finally, the tail should now point to the new last node
        tail->setPrev(newNode);
        //delete actualLast;
        //delete newNode;
    }
    /*cout << "entered push_back() method" << endl;
    DSNode<T> myNode;
    DSNode<T>* toAdd = &myNode;
    toAdd->setData(val);
    cout<< "set new node" << endl;
    if(head ==nullptr){
        cout << "size 0" << endl;
        toAdd->setNext(nullptr);
        toAdd->setPrev(nullptr);
        head = toAdd;
        tail = toAdd;
        cout << "tail: " << tail->getData() << endl;
    }
    else {
        cout << "size >0" << endl;
        DSNode<T>* current = tail;
        current->setNext(toAdd);
        toAdd->setPrev(current);
        toAdd->setNext(nullptr);
        tail = toAdd;
        cout << "tail: " << tail->getData()<< endl;
    }
     */
    size++;
}
/**
 *
 * @param val
 */
template<class T>
void DSList<T>::push_back(DSNode<T>* val){
    //TODO
    size--;
}
template<class T>
void DSList<T>::deleteAt(int loc){
    if(loc == 0){
        pop_front();
    }
    else if(loc == size-1){
        pop_back();
    }
    else {
        DSNode<T> current = new DSNode<T>;
        current = head;
        for (int i = 0; i < loc; i++) {
            current = current->next;
        }
        (current->prev).setNext(current->next);
        (current->next).setPrev(current->prev);
        delete current;
        size--;
    }
}
template<class T>
bool DSList<T>::remove(DSNode<T>* r){
//TODO
    if (isEmpty()) {
        // If the list is empty, it will return "false"
        return false;;
    }

    // Declares a pointer for searching the node to remove
    DSNode<T> *removeNode = tail->getPrev();
    while (removeNode!=nullptr) {
        if (removeNode==r) {
            // If the node is found, interrupts the loop
            break;
        }
        removeNode = removeNode->getPrev();
    }

    if (removeNode==nullptr) {
        // If the node we want to remove does not exist, returns false
        return false;
    }
    else {
        // Otherwise, declares 2 pointers for the node that folows the node to remove and for the node prior it
        DSNode<T> *afterRemove = removeNode->getNext();
        DSNode<T> *beforeRemove = removeNode->getNext();
        if (afterRemove==nullptr) {
            // If the pointer for the following node is NULL we are removing at the tail
            tail->setPrev(beforeRemove);
        }
        else {
            // Otherwise, we change its pointer "previous" to point to the node prior to the one we want to remove
            afterRemove->setPrev(beforeRemove);
        }
        if (beforeRemove==nullptr) {
            // If the pointer for the prior node is NULL we are removing at the head
            head->setNext(afterRemove);
        }
        else {
            // Otherwise, we change its pointer "next" to point to the node that follows the one we want to remove
            beforeRemove->setNext(afterRemove);
        }
        // Finally, releases the node from memory
        size--;
        delete removeNode;
        return true;
    }

}

template<class T>
void DSList<T>::clear(){
    if(size!=0) {
        DSNode<T> *current = head->getNext();
        //current = head->getNext();
        while (current->getNext() != nullptr) {
            current = current->getNext();
            delete current->getPrev();
        }
    }
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<class T>
DSNode<T> DSList<T>::pop_back(){
    DSNode<T>* tempPrev = tail-> getPrev()->getPrev();

    DSNode<T>* tempTail = new DSNode<T>;
    //tempPrev = tail-> getPrev()->getPrev();
    tempTail->setData(tail->getPrev()->getData());
    tempTail->setPrev(tail->getPrev()->getPrev());
    tempTail->setNext(tail);
    if(tempPrev != nullptr){
        (tempPrev)->setNext(tail);
    }

    delete tail->getPrev();
    size--;
    tail->setPrev(tempPrev);// = tempPrev;
    return *tempTail;

}
template<class T>
DSNode<T> DSList<T>::pop_front(){
    DSNode<T> node1;
    DSNode<T> node2;
    DSNode<T>* tempNext = &node1;
    DSNode<T>* tempHead = &node2;
    tempNext = head->getNext();
    tempHead->setData(head->getData());
    tempHead->setPrev(head->getPrev());
    tempHead->setNext(head->getNext());
    (head->getNext())->setPrev(nullptr);
    delete head;
    size--;
    head = tempNext;
    return *tempHead;
}



#endif //PA04_AMAZING_DSLIST_H
