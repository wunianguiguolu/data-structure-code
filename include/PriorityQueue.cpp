#include <iostream>
#include "../include/PriorityQueue.hpp"
#include "../include/utils.hpp"

template <class elemType>
void PriorityQueue<elemType>::doubleSpace()
{ 
    elemType *tmp =array;
    array = new elemType[2 * maxSize];
    for (int i = 0; i < maxSize; ++i)  //队列从front之后第一个元素开始
        array[i] = tmp[i];  //按照顺序复制

    maxSize *= 2;
    delete tmp;
}

template <class elemType>
void PriorityQueue<elemType>::enQueue(const elemType &x)
{  
    if (currentSize == maxSize - 1 )  doubleSpace();
    // 向上过滤
    int hole = ++currentSize;  //先不放x
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;  //hole == 1 或者 x > array[hole / 2];
}

template <class elemType>
elemType PriorityQueue<elemType>::deQueue()
{ 
    elemType minItem;
    minItem = array[1];
    array[1] = array[currentSize--];  //先保证结构性
    percolateDown(1);
    return minItem;
}

template <class elemType>
void PriorityQueue<elemType>::percolateDown(int hole)
{  
    int child;
    elemType tmp = array[hole];

    for (; hole * 2 <= currentSize; hole = child)
    {  
        child = hole * 2;  //child为最小孩子下标
        if (child != currentSize && array[child + 1] < array[child ])
            child++;
        if (array[child] < tmp)   
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

template <class elemType>
void PriorityQueue<elemType>::buildHeap( )
{  
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}

template <class elemType>
PriorityQueue<elemType>::PriorityQueue(const elemType *items, int size) : maxSize(size + 10), currentSize(size)
{
    array = new elemType[maxSize];
    for (int i = 0; i < size; i++)
        array[i + 1] = items[i];
    buildHeap();
}


template class PriorityQueue<int>;
template class PriorityQueue<double>;
template class PriorityQueue<char>;