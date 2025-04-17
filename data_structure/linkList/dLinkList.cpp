//
//  dLinkList.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//
#include "dLinkList.h"
#include <iostream>
using namespace std;

template <typename elemType>
dLinkList<elemType>::dLinkList()
{
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
    currentLength = 0;
}

template <typename elemType>
typename dLinkList<elemType>::node* dLinkList<elemType>::move(int i) const
{
    node *p = head->next;
    while(i-- > 0)
    {
        p = p->next;
    }
    return p;
}

template <typename elemType>
void dLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos = move(i);
    node *newNode = new node(x, pos->prev, pos);
    pos->prev->next = newNode;
    pos->prev = newNode;
    ++currentLength;
}

template <typename elemType>
void dLinkList<elemType>::remove(int i)
{
    node *tmp = move(i);
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
    --currentLength;
}

template <typename elemType>
void dLinkList<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = tail;
    tail->prev = head;
    while(p != tail)
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template <typename elemType>
int dLinkList<elemType>::search(const elemType &x,int i) const
{
    node *p = move(i);
    while(p != tail && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if(p == tail)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template <typename elemType>
elemType dLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}

template <typename elemType>
void dLinkList<elemType>::traverse() const
{
    node *p = head->next;
    cout << endl;
    while(p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
