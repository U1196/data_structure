//
//  dLinkList.h
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//
#ifndef DLINKLIST_H
#define DLINKLIST_H

#include "list.h"

template <typename elemType>
class dLinkList: public list<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next, *prev;
        node(const elemType &x, node *p = nullptr, node *q = nullptr)
        {
            next = q;
            prev = p;
            data = x;
        }
        node(): next(nullptr), prev(nullptr){}
        ~node(){}
    };
    node *head, *tail;
    int currentLength;
    node* move(int i) const;
public:
    dLinkList();
    ~dLinkList()
    {
        clear();
        delete head;
        delete tail;
    }
    void clear();
    int length() const {return currentLength;}
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType &x, int i) const;
    elemType visit(int i) const;
    void traverse() const;
};
#endif
