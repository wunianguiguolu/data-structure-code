#include <iostream>
#include "../include/BTree.hpp"
#include "../include/SequenceQueue.hpp"
 
template<class elemType>
void BTree<elemType>::createTree(const elemType &flag)
{
    SequenceQueue<Node*> que;
    elemType e, el, er;
    Node *p, *pl, *pr;
    stopFlag = flag;
    std::cout << "Please input the root: ";
    std::cin >> e;
    if ( e == stopFlag ) { root = NULL; return; }
    p = new Node(e);
    root = p;
    que.enQueue(p);
    while( !que.isEmpty()){
        p = que.getHead();
        que.deQueue();
        std::cout << "Please input the left child and the right child of " << p->data 
             << " using " << flag << " as no child: ";
        std::cin>>el>>er;
        if ( el != flag){
            pl = new Node(el);
            p->left = pl;
            que.enQueue(pl);
        }
        if ( er != flag){
            pr = new Node(er);
            p->right = pr;
            que.enQueue(pr);
        }
    }
    std::cout << std::endl;
}

template<class elemType>
void BTree<elemType>::LevelOrder()
{
    SequenceQueue<Node *> que;
    Node *p;

    if ( !root ) return;
    que.enQueue(root);
    while( !que.isEmpty()){
        p = que.getHead();
        que.deQueue();
        std::cout << p->data << " ";
        if ( p->left ){
            que.enQueue(p->left);
        }
        if ( p->right ){
            que.enQueue(p->right);
        }
    }
}

template<class elemType>
void BTree<elemType>::PreOrder(Node *t)
{
    if ( !t ) return;
    std::cout << t->data << " ";
    PreOrder( t->left );
    PreOrder( t->right );
}

template<class elemType>
void BTree<elemType>::InOrder(Node *t)
{
    if ( !t ) return;
    InOrder( t->left );
    std::cout << t->data << " ";
    InOrder( t->right );
}

template<class elemType>
void BTree<elemType>::PostOrder(Node *t)
{
    if ( !t ) return;
    PostOrder( t->left );
    PostOrder( t->right );
    std::cout << t->data << " ";
}

template<class elemType>
int BTree<elemType>::Size()
{
    return Size(root);
}

template<class elemType>
int BTree<elemType>::Height()
{
    return Height(root);
}

template<class elemType>
void BTree<elemType>::DelTree()
{
    DelTree(root);
}

template<class elemType>
int BTree<elemType>::Size(Node *t)
{
    if ( !t ) return 0;
    return 1 + Size(t->left) + Size(t->right);
}

template<class elemType>
int BTree<elemType>::Height(Node *t)
{
    int hl, hr;
    if ( !t ) return 0;
    hl = Height(t->left);
    hr = Height(t->right);
    if ( hl > hr ) return 1 + hl;
    return 1 + hr;
}

template<class elemType>
void BTree<elemType>::DelTree(Node *t)
{
    if ( !t ) return;
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

template class BTree<int>;
template class BTree<double>;
template class BTree<char>;