//
//  queue.h
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#ifndef QUEUE_H
#define QUEUE_H
template <typename elemType>
class queue
{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() const = 0;
    virtual ~queue(){}
};
#endif
