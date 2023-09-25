#ifndef __LinkList__
#define __LinkList__

#include "List.hpp"

class OutOfBound{};
class IllegalSize{};
template <class elemType>
class LinkList : public List<elemType>
{
private:
	struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *p = NULL)
        {data = x; next = p;}
        node():next(NULL) {}
        ~node() {}
    };

    node *head;
    
public:
	LinkList();
	~LinkList(){clear(); delete head;}
	void clear();
	void insert(int i, const elemType &x);
    void insert(elemType a[], int n);
	int length() const;
	void remove(int i);
    void reverse();
	int search(const elemType &x) const;
	void traverse() const;	
	elemType visit(int i) const;

};

#endif // defined(__LinkList__) */