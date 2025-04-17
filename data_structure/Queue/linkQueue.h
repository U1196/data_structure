//
//  link.h
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "queue.h"

template <typename elemType>
class linkQueue: public queue<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node* next = nullptr): data(x), next(next){}
        node():next(nullptr){}
        ~node(){}
    };
    node *front, *rear;
public:
    linkQueue();
    ~linkQueue();
    virtual bool isEmpty() const;
    virtual void enQueue(const elemType &x);
    virtual elemType deQueue();
    virtual elemType getHead() const;
};
#endif
