#ifndef __SequenceQueue__
#define __SequenceQueue__

#include "Queue.hpp"

template <class elemType>
class SequenceQueue : public Queue<elemType>
{
private:
    elemType *elem;
    int maxSize;
    int front, rear;

    void DoubleSpace();

public:
    SequenceQueue(int size = 10){
        front = rear = 0;
        elem = new elemType[size];
        maxSize = size;
    }
    ~SequenceQueue() {delete [] elem;}
    bool isEmpty() const {return front == rear;}
    elemType getHead() const;
    void enQueue(const elemType &x);
    elemType deQueue();
};

#endif // defined(__SequenceQueue__) */