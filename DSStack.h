//
// Created by robot on 3/23/2021.
//

#ifndef PA04_AMAZING_DSSTACK_H
#define PA04_AMAZING_DSSTACK_H

#include "DSList.h"
#include "DSNode.h"


template<class T>
class DSStack {
private:
    DSList<T> myList;

public:
    //constructors, detructors, etc
    DSStack();
    DSStack(DSStack<T>& val);
    ~DSStack();
    //operators

    DSStack<T>& operator = (const DSStack<T>& val);
    //mutators
    void push(const T& val);
    T pop();
    void clear();
    //accessors
    T& bottom();
    T& top();
    int getSize();
    //TODO contains(T item)
    int contains(T item);

};
//++++++++++ CONSTRUCTORS, DESTRUCTORS, ETC ++++++++++
template<class T>
DSStack<T>::DSStack(){

}
template<class T>
DSStack<T>::DSStack(DSStack<T>& val){
    myList = val.myList;
}
template<class T>
DSStack<T>::~DSStack(){
    myList.clear();
    //delete myList;
}
//++++++++++ OPERATORS ++++++++++
template<class T>
DSStack<T>& DSStack<T>::operator = (const DSStack<T>& val){
    myList = val.myList;
    return *this;
}
//++++++++++ MUTATORS ++++++++++
/**
 *
 * @param val
 */
template<class T>
void DSStack<T>::push(const T& val){
    myList.push_back(val);
}

/**
 *
 * @return
 */
template<class T>
T DSStack<T>::pop(){
    return (myList.pop_back()).getData();
}
/**
 * empties the DSStack
 */
template<class T>
void DSStack<T>::clear(){
    myList.clear();
}
//++++++++++ ACCESSORS ++++++++++
/**
 * gives value at the bottom of the DSStack
 * @return value at front of myList
 */
template<class T>
T& DSStack<T>::bottom(){
    return (*(myList.front())).getData();
}
/**
 * gives value at the top of the DSStack
 * @return value at back of myList
 */
template<class T>
T& DSStack<T>::top(){
    return (*(myList.back())).getData();
}
template<class T>
int DSStack<T>::getSize(){
    return myList.getSize();
}
template<class T>
int DSStack<T>::contains(T item){
    return myList.find(item);
}

#endif //PA04_AMAZING_DSSTACK_H
