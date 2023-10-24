#ifndef __Tree_H__
#define __Tree_H__

template <class elemType>     
class BTree                    
{
private:
	struct Node{
		Node *left, *right;
		elemType data;
		Node():left(NULL), right(NULL) {}
		Node(elemType item, Node *L = NULL, Node *R = NULL):
			data(item), left(L), right(R) {}
		~Node() {}	
	};
	Node *root;
	elemType stopFlag;
public:
	BTree(){root = NULL;}
	~BTree(){DelTree();}
	void createTree(const elemType &flag);
	bool isEmpty(){return (root == NULL);}
	Node *GetRoot(){return root;}
	int Size();
	int Height();
	void DelTree();
	void PreOrder(){PreOrder(root);}
	void InOrder(){InOrder(root);}
	void PostOrder(){PostOrder(root);}
	void LevelOrder();
private:
	int Size(Node *t);
	int Height(Node *t);
	void DelTree(Node *t);
	void PreOrder(Node *t);
	void InOrder(Node *t);
	void PostOrder(Node *t);
};

#endif //Tree.h