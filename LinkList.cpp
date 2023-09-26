#include <iostream>
#include "LinkList.hpp"

template<class elemType>
LinkList<elemType>::LinkList()
{
    head = new node();
}

template<class elemType>
void LinkList<elemType>::clear()
{
    
}

template<class elemType>
void LinkList<elemType>::insert(int i, const elemType &x)
{
    if (i < 0) return;
    node *tmp, *p = head;
    for (int j = 0; p && j <= i - 1; ++j) p = p->next;
    if (!p) return;
    tmp = new node(x, p->next);
    p->next = tmp;
}

template<class elemType>
void LinkList<elemType>::insert(elemType a[], int n)
{
    
}

template<class elemType>
int LinkList<elemType>::length() const
{
    int count = 0;
    node *p = head;
    while (p->next) {
        p = p->next;
        count++;    
    }
    return count;
}

template<class elemType>
void LinkList<elemType>::remove(int i)
{
    
}

template<class elemType>
void LinkList<elemType>::reverse()
{
    
}

template<class elemType>
int LinkList<elemType>::search(const elemType &x) const
{
    // # another implementation
    // int position = 0;
    // node *p = head->next;
    // while (p){
    //     if (p->data == x) return position;
    //     position++;
    //     p = p->next;
    // }
    // return -1;

    int pos = -1;
    node *p = head->next;
    while(p){
        pos++;
        if (p->data == x) break;
        p = p->next;
    }
    if(!p) return -1;
    return pos;
}

template<class elemType>
void LinkList<elemType>::traverse() const
{
    
}

template<class elemType>
elemType LinkList<elemType>::visit(int i) const
{
    
}

template class LinkList<int>;
template class LinkList<double>;