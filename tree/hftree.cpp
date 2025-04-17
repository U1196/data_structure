//
//  hftree.cpp
//  data_structure
//
//  Created by Fushimi on 2025/4/14.
//
#include "hftree.h"
using namespace std;
template<typename T>
hfTree<T>::hfTree(const T* v, const int* w, int size)
{
    const int MAX_INT = 32767;
    int min1, min2; //最小树和次小树的权值
    int x, y; //最小树和次小树的下标
    //设置初值
    int length = 2 * size;
    elem = new node[length];
    for(int i = size; i < length; ++i)
    {
        elem[i].data = v[i - size];
        elem[i].weight = w[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }
    //归并
    for(int i = size - 1; i > 0; --i)
    {
        min1 = min2 = MAX_INT;
        x = y = 0;
        for(int j = i + 1; j < length; ++j)
        {
            if(elem[j].parent == 0)
            {
                if(elem[j].weight < min1)
                {
                    y = x;
                    x = j;
                    min2 = min1;
                    min1 = elem[j].weight;
                }
                else if(elem[j].weight < min2)
                {
                    y = j;
                    min2 = elem[j].weight;
                }
            }
        }
        elem[i].weight = min1 + min2;
        elem[i].left = y;
        elem[i].right = x;
        elem[y].parent = elem[x].parent = i;
        elem[i].parent = 0;
    }
}

template<typename T>
void hfTree<T>::getCode(hfCode result[])
{
    int size = length / 2;
    int p, s; //s为正在处理的下标，p为s父结点下标
    for(int i = size; i < length; ++i)
    {
        result[i - size].data = elem[i].data;
        result[i - size].code = "";
        p = elem[i].parent;
        s = i;
        while(p) //在p非0，即p不是根结点
        {
            if(elem[p].left == s)
            {
                result[i - size].code = '0' + result[i - size];
            }
            else
            {
                result[i - size].code = '1' + result[i - size];
            }
            s = p;
            p = elem[p].parent;
        }
    }
}
