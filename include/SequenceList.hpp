#ifndef __SequenceList__
#define __SequenceList__

#include "List.hpp"

template <class elemType>
class SequenceList : public List<elemType>
{
private:
	elemType *data;
	int currentLength;
	int maxSize;
	void DoubleSpace();
public:
	SequenceList(int initSize = 10);
	~SequenceList(){delete [] data;}
	void clear();
	
	// void erase(int i);
	void insert(int i, const elemType &x);
	int length() const;
	void remove(int i);
	int search(const elemType &x) const;
	void traverse() const;	
	elemType visit(int position) const;

};

#endif // defined(__SequenceList__) */