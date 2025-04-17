//
//  slinkQueue.h
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#ifndef SLINKQUEUE_H
#define SLINKQUEUE_H
#include "queue.h"

template <typename elemType>
class slinkQueue
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &data, node *next = nullptr): data(data), next(next){}
        node(): next(nullptr){}
    };
    node* rear; //单循环链表实现了只用一个node指针，rear表示队尾，rear->next为队头，rear是否为空指针指示队列是否为空。
public:
    slinkQueue(){rear = nullptr;}
    ~slinkQueue();
    virtual bool isEmpty() const {return rear == nullptr;}
    virtual void enQueue(const elemType &x);
    virtual elemType deQueue();
    virtual elemType getHead() const {return rear->next->data;};
};
#endif
