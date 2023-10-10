#ifndef __LinkStack__
#define __LinkStack__

#include "Stack.hpp"
template <class elemType>
class LinkStack : public Stack<elemType>
{
private:
	struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node():next(NULL) {}
        ~node(){}
    }; 
    node *Top;
    
public:
    LinkStack();
    ~LinkStack();
    bool isEpmty() const;
    elemType top() const;
    void push(const elemType &x);
    elemType pop();

};

#endif // defined(__LinkStack__) */