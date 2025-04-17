//
//  linkQueue.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#include "linkQueue.h"

template <typename elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = nullptr;
}

template <typename elemType>
linkQueue<elemType>::~linkQueue()
{
    node *tmp;
    while(front != nullptr)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template <typename elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return front == nullptr;
}

template <typename elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if(rear == nullptr) //插入前为空队列
    {
        front = rear = new node(x);
    }
    else
    {
        rear = rear->next = new node(x);
    }
}

template <typename elemType>
elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}

template <typename elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    front = front->next;
    if(front == nullptr) //若删除栈顶后为空队列，那么删除的节点为原来rear指向的节点，需要重新设置rear
    {
        rear = nullptr;
    }
    elemType value = tmp->data;
    delete tmp;
    return value;
}
