//
//  seqQueue.h
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include "queue.h"
template <typename elemType>
class seqQueue: public queue<elemType>
{
private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();
public:
    seqQueue(int size = 10);
    virtual bool isEmpty() const;
    virtual void enQueue(const elemType &x);
    virtual elemType deQueue();
    virtual elemType getHead() const;
    virtual ~seqQueue(){delete[] elem;}
};
#endif
