#ifndef __HfTree_H__
#define __HfTree_H__

#include <string>

template <class elemType>
class HfTree
{
private:
    struct Node
    {
        elemType data;
        int weight;
        int parent, left, right;
    };

    Node *elem;
    int length;

public:
    struct HfCode
    {
        elemType data;
        std::string code;
    };
    HfTree(const elemType *v, const int *w, int size);
    void getCode(HfCode result[]);
    ~HfTree() {delete [] elem;}
};


#endif //HfTree.hpp