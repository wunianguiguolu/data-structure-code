#ifndef __List_H__
#define __List_H__

template <class elemType>     
class List                    
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int position, const elemType &x) = 0;
	virtual void remove(int position) = 0;
	virtual int search(const elemType &x) const = 0;
	virtual elemType visit(int position) const = 0;
	virtual void traverse() const = 0;
	// virtual void erase(int i) = 0;
	virtual ~List() {}
};

#endif //List.h

