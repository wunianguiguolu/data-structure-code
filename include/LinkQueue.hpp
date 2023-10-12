#ifndef __LinkQueue__
#define __LinkQueue__

#include "Queue.hpp"

template <class elemType>
class LinkQueue : public Queue<elemType>
{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL){
            data = x;
            next = N;
        }
        node():next(NULL) {}
        ~node() {}
    };
    node *front, *rear;

public:
    LinkQueue() {front = rear = NULL;}
    ~LinkQueue();
    bool isEmpty() const {return front == NULL;}
    elemType getHead() const;
    void enQueue(const elemType &x);
    elemType deQueue();
};

#endif // defined(__LinkQueue__) */