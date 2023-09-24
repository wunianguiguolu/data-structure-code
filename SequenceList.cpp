#include <iostream>
#include "SequenceList.hpp"

template <class elemType>
SequenceList<elemType>::SequenceList(int initSize)
{
    data = new elemType[initSize];
    if ( !data ) throw IllegalSize();
    maxSize = initSize;
    currentLength = 0;
}

template <class elemType>
void SequenceList<elemType>::clear()
{
    elemType *tmp = new elemType[maxSize];
    delete [] data;
    data = tmp;
    currentLength = 0;
}

template <class elemType>
void SequenceList<elemType>::doubleSpace()
{
    int j;
    elemType *tmp = new elemType [maxSize * 2];
    if (!tmp) throw IllegalSize();
    for (j = 0; j < currentLength; j++) tmp[j] == data[j];
    delete [] data;
    data = tmp;
    maxSize = maxSize * 2;
}

// template <class elemType>
// void SequenceList<elemType>::erase(int i)
// {

// }

template <class elemType>
void SequenceList<elemType>::insert(int i, const elemType &x)
{
    int j;
    if (i < 0 || i > currentLength) return;
    if (currentLength == maxSize)
        doubleSpace();
    for (j = currentLength; j > i; j--)
        data[j] = data[j - 1];
    data[i] = x;
    currentLength++;
}

template <class elemType>
int SequenceList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
void SequenceList<elemType>::remove(int i)
{
    int j;
    if (i < 0 || i >= currentLength) OutOfBound();
    for (j = i; j < currentLength; j++)
        data[j] = data[j + 1];
    --currentLength;
}

template <class elemType>
int SequenceList<elemType>::search(const elemType &x) const
{
    int i;
    for (i = 0; i < currentLength; i++)
        if (data[i] == x) break;
    if (i == currentLength) return -1;
    else return i;
}

template <class elemType>
void SequenceList<elemType>::traverse() const
{
    int i;
    for (i = 0; i < currentLength; i++)
    {
        std::cout << data[i] << " ";
    }
}

template <class elemType>
elemType SequenceList<elemType>::visit(int position) const
{
    if (position < 0 || position >= currentLength) OutOfBound();
    return data[position];
}

template class SequenceList<int>;
template class SequenceList<double>;

