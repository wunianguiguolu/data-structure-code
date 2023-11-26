#ifndef __PriorityQueue_H__
#define __PriorityQueue_H__

//PriorityQueue
template <class elemType>
class PriorityQueue
{
private:
    int currentSize;
    elemType *array;  //存储优先队列中元素
    int maxSize;

    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);  //向下过滤

public:
    PriorityQueue(int capacity = 100)
    { 
        array = new elemType[capacity];
        maxSize = capacity;
        currentSize = 0;
    }
    PriorityQueue(const elemType data[], int size);
    ~PriorityQueue() {delete [] array;}
    bool isEmpty() const {return currentSize == 0;}
    elemType getHead() {return array[1];}
    void enQueue(const elemType &x);
    elemType deQueue();
};

#endif //PriorityQueue.h