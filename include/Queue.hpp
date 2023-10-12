#ifndef __Queue_H__
#define __Queue_H__

template<class elemType>
class Queue
{
public:
    virtual bool isEmpty() const = 0;
    virtual elemType getHead() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual ~Queue() {}
};

#endif //Queue.h