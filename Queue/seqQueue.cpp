//
//  seqQueue.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#include <iostream>
#include "seqQueue.h"
using namespace std;

template <typename elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new elemType[size];
    front = rear = 0;
    maxSize = size;
}

template <typename elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return rear == front;
}

template <typename elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front + 1) % maxSize;
    return elem[front];
}

template <typename elemType>
elemType seqQueue<elemType>::getHead() const
{
    return elem[(front + 1) % maxSize];
}

template <typename elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if((rear + 1) % maxSize == front)
    {
        doubleSpace();
    }
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}

template <typename elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[maxSize * 2];
    for(int i = 1; i <= maxSize; ++i)
    {
        elem[i] = tmp[(front + i) % maxSize];
    }
    delete tmp;
    front = 0;
    rear = maxSize;
    maxSize *= 2;
}
