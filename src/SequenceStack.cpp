#include <iostream>
#include "../include/SequenceStack.hpp"
#include "../include/utils.hpp"
#include "../include/BTree.hpp"

template<class elemType>
SequenceStack<elemType>::SequenceStack(int initSize)
{
    elem = new elemType[initSize];
    if(!elem) throw IllegalSize();
    maxSize = initSize;
    Top = -1;
}

template<class elemType>
SequenceStack<elemType>::~SequenceStack()
{
    delete [] elem;
}

template<class elemType>
bool SequenceStack<elemType>::isEmpty() const
{
    return (Top == -1);
}   

template<class elemType>
elemType SequenceStack<elemType>::top() const
{
    if(Top == -1) throw OutOfBound();
    return elem[Top];
}

template<class elemType>
void SequenceStack<elemType>::push(const elemType &x)
{
    if(Top == maxSize - 1) DoubleSpace();
    elem[++Top] = x;
}

template<class elemType>
elemType SequenceStack<elemType>::pop()
{
    if(Top == -1) throw OutOfBound();
    return elem[Top--];
}

template<class elemType>
void SequenceStack<elemType>::DoubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[maxSize * 2];
    for(int i = 0; i < maxSize; i++) elem[i] = tmp[i];
    maxSize = maxSize * 2;
    delete [] tmp;
}

template class SequenceStack<int>;
template class SequenceStack<double>;
template class SequenceStack<BTree<int>::Node*>;
template class SequenceStack<BTree<double>::Node*>;
template class SequenceStack<BTree<char>::Node*>;