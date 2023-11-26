#include <iostream>
#include "../include/HfTree.hpp"

template <class elemType>
HfTree<elemType>::HfTree(const elemType *v, const int *w, int size)
//v:编码数据 w:权值 size:总结点数
{  
    const int MAX_INT = 32767;
    int min1, min2;  //最小树、次最小树的权值
    int x, y;  //最小树、次最小树的下标
    length = 2 * size;  //置初值
    elem = new Node[length];
    for (int i = size; i < length; ++i)
    { 
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }
    // 构造新的二叉树
    for (int i = size - 1; i > 0; --i)  //从下标最大的内部节点开始，到根结点
    { 
        min1 = min2 = MAX_INT; x = y = 0;
        for (int j = i + 1; j < length; ++j) //找到最小的两个
        {
            if (elem[j].parent == 0) 
            {
                if (elem[j].weight < min1)
                {
                    min2 = min1; min1 = elem[j].weight; 
                    x = y; y = j;
                }
                else if (elem[j].weight < min2)
                {
                    min2 = elem[j].weight; x = j; 
                }
            }  //end if
        }  //end for inner
        elem[i].weight = min1 + min2; //合并最小的两个
        elem[i].left = x; elem[i].right = y; elem[i].parent = 0;
        elem[x].parent = i; elem[y].parent = i;
    }  //end for outer
}  //end

template <class elemType>
void HfTree<elemType>::getCode(HfCode result[])
{
    int size = length / 2;
    int p,s;  //s是追溯过程中正在处理的结点，p是s的父结点下标
    for (int i = size; i < length; ++i)
    {
        result[i - size].data = elem[i].data; // 对每个待编码的符号
        result[i - size].code = std::string("");
        p = elem[i].parent; s = i;
        while (p) 
        { // while（p!=0）
            if (elem[p].left == s)  //是父结点的左孩子编码末尾加0
                result[i - size].code = "0" + result[i -size].code;
            else 
                result[i - size].code = "1" + result[i - size].code;  //加1
                s = p; p = elem[p].parent; //向上一层
        }  
    }  
}

template class HfTree<int>;
template class HfTree<double>;
template class HfTree<char>;