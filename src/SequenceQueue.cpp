#include <iostream>
#include "../include/SequenceQueue.hpp"
#include "../include/utils.hpp"
 
template<class elemType>
elemType SequenceQueue<elemType>::getHead() const
{
    if(front == rear) throw OutOfBound();
    return elem[(front + 1) % maxSize];
}

template<class elemType>
void SequenceQueue<elemType>::enQueue(const elemType &x)
{
    if((rear + 1) % maxSize == front) DoubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}

template<class elemType>
elemType SequenceQueue<elemType>::deQueue()
{
    if(front == rear) throw OutOfBound();
    front = (front + 1) % maxSize;
    return elem[front];
}

template<class elemType>
void SequenceQueue<elemType>::DoubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[maxSize * 2];
    for(int i = 0; i < maxSize; i++) elem[i] = tmp[(front + i) % maxSize];
    front = 0; rear = maxSize - 1;
    maxSize *= 2;
    delete [] tmp;
}

template class SequenceQueue<int>;
template class SequenceQueue<double>;