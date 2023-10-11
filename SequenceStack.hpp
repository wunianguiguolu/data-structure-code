#ifndef __SequenceStack__
#define __SequenceStack__

#include "Stack.hpp"
template <class elemType>
class SequenceStack : public Stack<elemType>
{
private:
	elemType *elem;
    int Top;
    int maxSize;
    void DoubleSpace();
    
public:
    SequenceStack(int initSize = 10);
    ~SequenceStack();
    bool isEmpty() const;
    elemType top() const;
    void push(const elemType &x);
    elemType pop();

};

#endif // defined(__SequenceStack__) */