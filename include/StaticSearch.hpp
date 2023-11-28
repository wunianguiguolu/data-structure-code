#ifndef __StaticSearch_H__
#define __StaticSearch_H__

template <class KEY, class OTHER>
struct SET {
    KEY key;  //如学号
    OTHER other;  //包含姓名、性别、出生日期等的结构体变量
};

//无序表的顺序查找
template <class KEY, class OTHER>
int seqSearch_unordered(SET<KEY, OTHER> data[],
                        int size, const KEY &x);
//有序表的顺序查找
template <class KEY, class OTHER>
int seqSearch_ordered(SET<KEY, OTHER> data[],
                      int size, const KEY &x);

//二分查找
template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[],
                 int size, const KEY &x);

#endif //StaticSearch.h
