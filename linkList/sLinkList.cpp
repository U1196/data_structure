//
//  sLinkList.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//
#include "list.h"
#include "sLinkList.h"
#include <iostream>

template <typename elemType>
typename sLinkList<elemType>::node* sLinkList<elemType>::move(int i) const
{
    node* p = head;
    while(i-- >= 0)
    {
        p = p->next;
    }
    return p;
}

template <typename elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}

template<typename elemType>
void sLinkList<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = nullptr;
    while(p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template<typename elemType>
void sLinkList<elemType>::insert(const elemType &x, int i)
{
    node* pos = move(i - 1);
    pos->next = new node(x, pos->next);
    ++currentLength;
}

template<typename elemType>
void sLinkList<elemType>::remove(int i)
{
    node *pos, *delp;
    pos = move(i - 1);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --currentLength;
}

template<typename elemType>
int sLinkList<elemType>::search(const elemType &x)const
{
    node *p = head->next;
    int i;
    for(i = 0; p != nullptr && p->data != x; ++i);
    if(p == nullptr)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template<typename elemType>
elemType sLinkList<elemType>::visit(int i)const
{
    return move(i)->data;
}

template<typename elemType>
void sLinkList<elemType>::traverse()const
{
    node *p = head->next;
    std::cout << std::endl;
    while(p != nullptr)
    {
        std::cout << p->data << '-';
        p = p->next;
    }
    std::cout << std::endl;
}

template<typename elemType>
void sLinkList<elemType>::erase(int i)
{
    node *pre = move(i - 1);
    node *delp = pre->next;
    elemType tmp = delp->data;
    int cnt = 1;
    pre->next = delp->next;
    delete delp;
    for(pre = head->next; pre != nullptr; pre = pre->next)
    {
        if(pre->next->data == tmp)
        {
            delp = pre->next;
            pre->next = delp->next;
            delete delp;
            ++cnt;
        }
    }
    currentLength -= cnt;
}
