#include <iostream>
#include "LinkList.hpp"
#include "utils.hpp"

template<class elemType>
LinkList<elemType>::LinkList()
{
    head = new node();
}

template<class elemType>
void LinkList<elemType>::clear()
{
    node *p, *q;
    p = head->next;
    head->next = NULL;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    // delete p; why we can't delete the pointer p
    return;
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
    node *tmp;
    for (int i = 0; i < n; i++){
        // tmp = node(a[i],  head->next); 
        tmp = new node(a[i],  head->next);
        head->next = tmp; 
    }
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
    if(i < 0 || i >= length()) return;
    node *tmp;
    node *p = head;
    for(int j = 0; j < i && p->next != NULL; j++) p = p->next;
    tmp = p->next;
    p->next = tmp->next;
    delete tmp; 
    if(p->next == NULL) p = NULL;
}

template<class elemType>
void LinkList<elemType>::reverse()
{
    node *q, *p = head->next;
    head->next = NULL;
    while(p){
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

template<class elemType>
int LinkList<elemType>::search(const elemType &x) const
{
    // ### another implementation
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
    node *p = head->next;
    if(!p) {
        std::cout << "There's nothing in the array!" << std::endl;
        return;
    }
    do{
        std::cout << p->data << " ";
        p = p->next;
    }while(p!=NULL);
    std::cout << std::endl;
    return;

}

template<class elemType>
elemType LinkList<elemType>::visit(int i) const
{
    if (i < 0 || i >= length()) OutOfBound();
    int j;
    node *p = head->next;
    for (j = 0; j < i; j++){
        p = p->next;
    }
    return p->data;
}

template class LinkList<int>;
template class LinkList<double>;