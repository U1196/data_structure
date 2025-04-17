//
//  linkStack.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/21.
//
#include <iostream>
#include "linkStack.h"
using namespace std;

template <typename elemType>
linkStack<elemType>::linkStack()
{
    top_p = nullptr;
}

template <typename elemType>
linkStack<elemType>::~linkStack()
{
    node *tmp;
    while(top_p != nullptr)
    {
        tmp = top_p->next;
        delete top_p;
        top_p = tmp;
    }
}

template <typename elemType>
bool linkStack<elemType>::isEmpty() const
{
    return top_p == nullptr;
}

template <typename elemType>
void linkStack<elemType>::push(const elemType &x)
{
    top_p = new node(x, top_p);
}

template <typename elemType>
elemType linkStack<elemType>::pop()
{
    node *tmp = top_p;
    top_p = top_p->next;
    elemType x = tmp->data;
    delete tmp;
    return x;
}

template <typename elemType>
elemType linkStack<elemType>::top() const
{
    return top_p->data;
}
