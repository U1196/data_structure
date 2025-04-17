//
//  hftree.h
//  data_structure
//
//  Created by Fushimi on 2025/4/14.
//
#ifndef HFTREE_H
#define HFTREE_H
#include <string>
template<typename T>
class hfTree
{
private:
    struct node
    {
        T data;
        int weight, parent, left, right;
    };
    node *elem;
    int length;
public:
    struct hfCode
    {
        T data;
        std::string code;
    };
    hfTree(const T* v, const int* w, int size);
    void getCode(hfCode result[]);
    ~hfTree(){delete[] elem;}
};
#endif
