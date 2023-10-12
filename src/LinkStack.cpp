#include <iostream>
#include "../include/LinkStack.hpp"
#include "../include/utils.hpp"

template<class elemType>
LinkStack<elemType>::LinkStack()
{
    Top = NULL;
}

template<class elemType>
LinkStack<elemType>::~LinkStack()
{
    node *tmp;
    while(Top!=NULL)
    {
        tmp = Top;
        Top = Top->next;
        delete tmp;
    }
}

template<class elemType>
bool LinkStack<elemType>::isEmpty() const
{
    return Top == NULL;
}   

template<class elemType>
elemType LinkStack<elemType>::top() const
{
    if (Top == NULL) throw OutOfBound();
    return Top->data;
}

template<class elemType>
void LinkStack<elemType>::push(const elemType &x)
{
    Top = new node(x, Top);
}

template<class elemType>
elemType LinkStack<elemType>::pop()
{
    if(Top == NULL) throw OutOfBound();
    elemType value = Top->data;
    node* tmp = Top;
    Top = Top->next;
    delete tmp;
    return value;
}

template class LinkStack<int>;
template class LinkStack<double>;