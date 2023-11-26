#include <iostream>
#include <cmath>
#include "../include/BTree.hpp"
#include "../include/SequenceQueue.hpp"
#include "../include/SequenceStack.hpp"
#include "../include/SequenceList.hpp"
 
template<class elemType>
void BTree<elemType>::createTree(const elemType &flag)
{
    SequenceQueue<Node*> que;
    elemType e, el, er;
    Node *p, *pl, *pr;
    stopFlag = flag;
    std::cout << "Please input the root: ";
    std::cin >> e;
    if ( e == stopFlag ) { root = NULL; return; }
    p = new Node(e);
    root = p;
    que.enQueue(p);
    while( !que.isEmpty()){
        p = que.getHead();
        que.deQueue();
        std::cout << "Please input the left child and the right child of " << p->data 
             << " using " << flag << " as no child: ";
        std::cin>>el>>er;
        if ( el != flag){
            pl = new Node(el);
            p->left = pl;
            que.enQueue(pl);
        }
        if ( er != flag){
            pr = new Node(er);
            p->right = pr;
            que.enQueue(pr);
        }
    }
    std::cout << std::endl;
}

template<class elemType>
void BTree<elemType>::LevelOrder()
{
    SequenceQueue<Node *> que;
    Node *p;

    if ( !root ) return;
    que.enQueue(root);
    while( !que.isEmpty()){
        p = que.getHead();
        que.deQueue();
        std::cout << p->data << " ";
        if ( p->left ){
            que.enQueue(p->left);
        }
        if ( p->right ){
            que.enQueue(p->right);
        }
    }
}

template<class elemType>
void BTree<elemType>::PreOrder(Node *t)
{
    if ( !t ) return;
    std::cout << t->data << " ";
    PreOrder( t->left );
    PreOrder( t->right );
}

template<class elemType>
void BTree<elemType>::InOrder(Node *t)
{
    if ( !t ) return;
    InOrder( t->left );
    std::cout << t->data << " ";
    InOrder( t->right );
}

template<class elemType>
void BTree<elemType>::PostOrder(Node *t)
{
    if ( !t ) return;
    PostOrder( t->left );
    PostOrder( t->right );
    std::cout << t->data << " ";
}

template<class elemType>
int BTree<elemType>::Size()
{
    return Size(root);
}

template<class elemType>
int BTree<elemType>::Height()
{
    return Height(root);
}

template<class elemType>
void BTree<elemType>::DelTree()
{
    DelTree(root);
}

template<class elemType>
int BTree<elemType>::Size(Node *t)
{
    if ( !t ) return 0;
    return 1 + Size(t->left) + Size(t->right);
}

template<class elemType>
int BTree<elemType>::Height(Node *t)
{
    int hl, hr;
    if ( !t ) return 0;
    hl = Height(t->left);
    hr = Height(t->right);
    if ( hl > hr ) return 1 + hl;
    return 1 + hr;
}

template<class elemType>
void BTree<elemType>::DelTree(Node *t)
{
    if ( !t ) return;
    DelTree(t->left);
    DelTree(t->right);
    delete t;
}

template <class elemType>
void BTree<elemType>::PreOrder_NonRec()
{
    if (!root) return;
    Node *p;
    SequenceStack<Node *> s;
    s.push(root);
    while (!s.isEmpty()){
        p=s.top(); 
        s.pop();
        std::cout << p->data << " ";
        if (p->right) s.push(p->right);
        if (p->left) s.push(p->left);
    }
}

template <class Type>
void BTree<Type>::InOrder_NonRec()
{
    if (!root) return;
    SequenceStack<Node *> s1;
    SequenceStack<int> s2;
    Node *p;
    int flag;
    int zero=0, one=1;
    p = root;
    s1.push(p); 
    s2.push(zero);

    while (!s1.isEmpty()){
        flag = s2.top();
        s2.pop();
        p = s1.top();  //读取栈顶元素

        if (flag == 1)  //二次出栈，则访问
        { 
            s1.pop();
            std::cout << p->data << " ";
            if (!p->right) continue;
            //有右子压右子，没有进入下一轮循环
            s1.push(p->right);
            s2.push(zero);
            // if (p->right)  //有左子压左子
            // {
            //     s1.push(p->right);
            //     s2.push(zero);
            // }
        }
        else  //首次出栈，则入栈，标1
        {
            s2.push(one);
            if (p->left)  //有左子压左子
            {
                s1.push(p->left);
                s2.push(zero);
            }
        }
    } //end while
}//end

template <class elemType>
void BTree<elemType>::PostOrder_NonRec()
//后序遍历的非递归算法实现。
{
    if (!root) return;

    Node *p;
    SequenceStack<Node *> s1;
    SequenceStack<int> s2;
    int zero = 0, one = 1, two = 2;
    int flag;
    s1.push(root);
    s2.push(zero);

    while (!s1.isEmpty())
    {
        flag = s2.top(); s2.pop();
        p = s1.top();
        switch(flag) 
        {
            case 2:
                s1.pop();
                std::cout << p->data << " ";
                break;
            case 1: 
                s2.push(two);
                if (p->right) 
                {
                    s1.push(p->right);
                    s2.push(zero);
                }
                break;
            case 0:
                s2.push(one);
                if (p->left) 
                {
                    s1.push(p->left);
                    s2.push(zero);
                }
                break;
        };  //switch
    }  //while
}

template <class elemType>
typename BTree<elemType>::Node* BTree<elemType>::buildTree_pre_mid(elemType pre[], int pl, int pr,
                                                             elemType mid[], int ml, int mr)
//pre数组存储了前序遍历序列，pl为序列左边界下标，
//pr为序列右边界下标。
//mid数组存储了中序遍历序列，ml为序列左边界下标，
//mr为序列右边界下标。
{
    Node *p, *leftRoot, *rightRoot;
    int i, pos, num;
    int lpl, lpr, lml, lmr;  //左子树中前序的左右边界、中序的左右边界
    int rpl, rpr, rml, rmr;  //右子树中前序的左右边界、中序的左右边界
    if (pl > pr) return NULL;
    p = new Node(pre[pl]);  //找到子树的根并创建结点
    if (!root) root = p;

    //找根在中序中的位置和左子树中结点个数
    for (i = ml; i <= mr; i++)
        if (mid[i] == pre[pl]) break;
    pos = i;  //子树根在中序中的下标
    num = pos - ml;  //子树根的左子树中结点的个数
    //找左子树的前序、中序序列下标范围
    lpl = pl + 1; lpr = pl + num;
    lml = ml; lmr = pos - 1;
    leftRoot = buildTree_pre_mid(pre, lpl, lpr, mid, lml, lmr);
    //找右子树的前序、中序序列下标范围
    rpl = pl + num + 1; rpr = pr;
    rml = pos + 1; rmr = mr;
    rightRoot = buildTree_pre_mid(pre, rpl, rpr, mid, rml, rmr);
    p->left = leftRoot; p->right = rightRoot;
    return p; 
}

template <class elemType>
typename BTree<elemType>::Node* BTree<elemType>::buildTree_post_mid(elemType post[], int pl, int pr,
                                                             elemType mid[], int ml, int mr)
//post数组存储了后序遍历序列，pl为序列左边界下标，
//pr为序列右边界下标。
//mid数组存储了中序遍历序列，ml为序列左边界下标，
//mr为序列右边界下标。
{
    Node *p, *leftRoot, *rightRoot;
    int i, pos, num;
    int lpl, lpr, lml, lmr;  //左子树中后序的左右边界、中序的左右边界
    int rpl, rpr, rml, rmr;  //右子树中后序的左右边界、中序的左右边界
    if (pl > pr) return NULL;
    p = new Node(post[pr]);  //找到子树的根并创建结点
    if (!root) root = p;

    //找根在中序中的位置和左子树中结点个数
    for (i = ml; i <= mr; i++)
        if (mid[i] == post[pr]) break;
    pos = i;  //子树根在中序中的下标
    num = pos - ml;  //子树根的左子树中结点的个数
    //找左子树的后序、中序序列下标范围
    lpl = pl; lpr = pl + num - 1;
    lml = ml; lmr = pos - 1;
    leftRoot = buildTree_post_mid(post, lpl, lpr, mid, lml, lmr);
    //找右子树的后序、中序序列下标范围
    rpl = pl + num; rpr = pr - 1;
    rml = pos + 1; rmr = mr;
    rightRoot = buildTree_post_mid(post, rpl, rpr, mid, rml, rmr);
    p->left = leftRoot; p->right = rightRoot;
    return p; 
}

template <class elemType>
typename BTree<elemType>::Node* BTree<elemType>::buildCompleteBinaryTree(int n)
{
    int initSize = n;
    Node *pl, *pr, *p;
    int el, er;
	SequenceList<int> arr(initSize);
    int level_num = 1;
    while (n > 2 || n == 2){
        level_num++;
        n = n / 2;
    }
    for (int i = 0; i < std::pow(2, level_num - 1); i++){
        if (n - i > 0){
            arr.insert(i, n - i);
        }
        else{
            arr.insert(i, 0);
        }
    }
    SequenceQueue<Node*> que;
    p = new Node(arr.visit(0));
    root = p;
    que.enQueue(p);
    for (int j = 0; j < std::pow(2, level_num - 1) - 1 ; j++){
        p = que.getHead();
        que.deQueue();
        el = arr.visit(j * 2 + 1);
        er = arr.visit(j * 2 + 2);
        pl = new Node(el);
        pr = new Node(er);
        p->left = pl;
        p->right = pr;
        que.enQueue(pl);
        que.enQueue(pr);
    }

    return root; 
}

template class BTree<int>;
template class BTree<double>;
template class BTree<char>;