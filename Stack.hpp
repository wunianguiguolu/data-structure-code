#ifndef __Stack_H__
#define __Stack_H__

template <class elemType>     
class Stack                    
{
public:
	virtual bool isEpmty() const = 0;
	virtual elemType top() const = 0;
	virtual void push(const elemType &x) = 0;
	virtual elemType pop() = 0;
	virtual ~Stack() {};
};

#endif //Stack.h

