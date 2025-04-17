//
//  slinkQueue.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/24.
//
#include "slinkQueue.h"

template <typename elemType>
slinkQueue<elemType>::~slinkQueue()
{
    if(rear == nullptr)
    {
        return;
    }
    node *delp, *tmp;
    delp = rear->next;
    rear = nullptr; //rear需要保留并且设置为空队列状态
    while(delp != nullptr)
    {
        tmp = delp;
        delp = delp->next;
        delete tmp;
    }
}

template <typename elemType>
void slinkQueue<elemType>::enQueue(const elemType &x)//在rear后面插入node
{
    if(rear == nullptr)//插入前为空队列
    {
        rear = new node(x, rear);
    }
    else
    {
        rear = rear->next = new node(x, rear->next);
    }
}

template <typename elemType>
elemType slinkQueue<elemType>::deQueue() //删除rear指向的下一个节点，即队头
{
    node *tmp = rear->next;
    if(rear == tmp)
    {
        rear = nullptr;
    }
    else
    {
        rear->next = tmp->next;
    }
    elemType value = tmp->data;
    delete tmp;
    return value;
}
