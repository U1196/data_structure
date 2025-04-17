//
//  seqStack.h
//  data_structure
//
//  Created by Fushimi on 2025/3/20.
//
#ifndef SEQSTACK_H
#define SEQSTACK_H
#include "newstack.h"
#include <iostream>
using namespace std;

template <typename elemType>
class seqStack: public newstack<elemType>
{
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize = 10);
    virtual ~seqStack();
    virtual bool isEmpty() const;
    virtual void push(const elemType &x);
    virtual elemType pop();
    virtual elemType top() const;
};

template <typename elemType>
seqStack<elemType>::seqStack(int initSize)
{
    elem = new elemType[initSize];
    maxSize = initSize;
    top_p = -1;
}

template <typename elemType>
seqStack<elemType>::~seqStack()
{
    delete[] elem;
}

template <typename elemType>
bool seqStack<elemType>::isEmpty() const
{
    return top_p == -1;
}

template <typename elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if(top_p == maxSize)
    {
        doubleSpace();
    }
    elem[++top_p] = x;
}

template <typename elemType>
elemType seqStack<elemType>::pop()
{
    return elem[top_p--];
}

template <typename elemType>
elemType seqStack<elemType>::top() const
{
    return elem[top_p];
}

template <typename elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[maxSize * 2];
    for(int i = 0; i < maxSize; ++i)
    {
        elem[i] = tmp[i];
    }
    maxSize *= 2;
    delete [] tmp;
}

#endif
