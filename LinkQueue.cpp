#include <iostream>
#include "LinkQueue.hpp"
#include "utils.hpp"
  
template<class elemType>
LinkQueue<elemType>::~LinkQueue() 
{
    node *tmp;
    while(front != NULL){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class elemType>
elemType LinkQueue<elemType>::getHead() const
{
    if(front == NULL) throw OutOfBound();
    return front->data;
}

template<class elemType>
void LinkQueue<elemType>::enQueue(const elemType &x)
{
    if(rear == NULL) {
        front = rear = new node(x);
    }
    else{
        rear->next = new node(x);
        rear = rear->next;
    }
}

template<class elemType>
elemType LinkQueue<elemType>::deQueue()
{
    if(front == NULL) throw OutOfBound();
    node *tmp = front;
    elemType value = front->data; 
    front = front->next;
    if(front == NULL) rear = NULL;
    delete tmp;
    return value;
}

template class LinkQueue<int>;
template class LinkQueue<double>;