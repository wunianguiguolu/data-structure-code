#include "../include/StaticSearch.hpp"

//无序表的顺序查找
template <class KEY, class OTHER>
int seqSearch_unordered(SET<KEY, OTHER> data[],
                        int size, const KEY &x)
{  
    int i;
    data[0].key = x;
    for (i = size ; x != data[i].key; --i);  //默认数据由小到大有序
    return i;
}

//有序表的顺序查找
template <class KEY, class OTHER>
int seqSearch_ordered(SET<KEY, OTHER> data[],
                      int size, const KEY &x)
{  
    int i;
    data[0].key = x;
    for (i = size ; x < data[i].key; --i);  //默认数据由小到大有序
        if (x == data[i].key) return i;
    else return 0;
}

//二分查找
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[],
                 int size, const KEY &x)
{      
    int low = 1, high = size, mid;
    while (low <= high) 
    {   //查找区间存在
        mid = (low + high) / 2;  //计算中间位置
        if ( x == data[mid].key )  return mid;
        if ( x < data[mid].key) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

template int seqSearch_unordered<int, char>(SET<int, char>*, int, int const&);
template int seqSearch_ordered<int, char>(SET<int, char>*, int, int const&);
template int binarySearch<int, char>(SET<int, char>*, int, int const&);
