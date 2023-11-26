#ifndef __BTree_H__
#define __BTree_H__

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
	
	void PreOrder(){PreOrder(root);}  //为用户调用封装的函数，用户不需要知道根节点，因此不需要根指针作为参数，前序遍历
	void PreOrder_NonRec();  //前序遍历非递归实现

	void InOrder (){InOrder(root);}  //按中序遍历输出二叉树的结点的数据值
	void InOrder_NonRec();  //中序遍历非递归实现

	void PostOrder(){PostOrder(root);}  //按后序遍历输出二叉树结点数据值
	void PostOrder_NonRec();  //后序遍历非递归实现
	
	void LevelOrder();
  	Node *buildTree_pre_mid(elemType pre[], int pl, int pr,
                  elemType mid[], int ml, int mr);
	Node *buildTree_post_mid(elemType post[], int pl, int pr,
                  elemType mid[], int ml, int mr);
	Node *buildCompleteBinaryTree(int n);
private:
	int Size(Node *t);
	int Height(Node *t);
	void DelTree(Node *t);
	void PreOrder(Node *t);
	void InOrder(Node *t);
	void PostOrder(Node *t);
};

#endif //BTree.hpp