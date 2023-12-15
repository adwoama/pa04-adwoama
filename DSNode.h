//
// Created by robot on 3/23/2021.
//

#ifndef PA04_AMAZING_DSNODE_H
#define PA04_AMAZING_DSNODE_H
template<class T>
class DSNode {
private:
    T data;
    DSNode<T>* next;
    DSNode<T>* prev;

public:
    //DSNode();
    DSNode(const T &e = T(), DSNode<T> *n = {nullptr}, DSNode<T> *p = {nullptr});
    //DSNode(T val);
    DSNode(DSNode <T>& val);
    DSNode<T>& operator = (const DSNode<T>& val);
    ~DSNode();
    //mutators
    void setNext(DSNode<T>* val);
    void setPrev(DSNode<T>* val);
    void setData(T val);
    //accessors
    DSNode<T>* & getNext();
    DSNode<T>* & getPrev();
    T& getData();


};

/*
template<class T>
DSNode<T>::DSNode(){
    next = nullptr;
    prev = nullptr;
}
 */
/*template<class T>
DSNode<T>::DSNode(T val){
    data = val;
    next = nullptr;
    prev = nullptr;
}
*/
template<class T>
DSNode<T>::DSNode(const T &e, DSNode<T> *n, DSNode<T> *p) //: data(e), next(n), prev(p) {}
{
    data = e;
    next = n;
    prev = p;
}
template<class T>
DSNode<T>::DSNode(DSNode <T>& val){
    data = val.data;
    next = val.next;
    prev = val.prev;
}
template<class T>
DSNode<T>& DSNode<T>::operator = (const DSNode<T>& val){
    data = val.data;
    next = val.next;
    prev = val.prev;
    return *this;
}
template<class T>
DSNode<T>::~DSNode(){
    /*if(next != nullptr)
        delete next;//SIGSEV segmentation fault on prev
    if(prev != nullptr)
        delete prev;
        */
    //next = nullptr;
    //prev = nullptr;
}

//+++++++++++ MUTATORS ++++++++
template<class T>
void DSNode<T>::setNext(DSNode<T>* val){
    next = val;
}//setNext
template<class T>
void DSNode<T>::setPrev(DSNode<T>* val){
    prev = val;
}//setPrev
template<class T>
void DSNode<T>::setData(T val){
    data = val;
}//setData
//++++++++++ ACCESSORS ++++++++++
template<class T>
DSNode<T>* & DSNode<T>::getNext(){
    return next;
}
template<class T>
DSNode<T>* & DSNode<T>::getPrev(){
    return prev;
}
template<class T>
T& DSNode<T>::getData(){
    return data;
}



#endif //PA04_AMAZING_DSNODE_H