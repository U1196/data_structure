//
//  sLinkList.h
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//
#ifndef SLINKLIST_H
#define SLINKLIST_H

#include "list.h"

template <typename elemType>
class sLinkList: public list<elemType>
{
private:
    struct node
    {
        elemType data;
        node* next;
        
        node(): next{nullptr}{}
        node(const elemType &x, node *n = nullptr)
        {
            data = x;
            next = n;
        }
        ~node(){}
    };
    node *head;
    int currentLength;
    node* move(int i) const; //return the address of the nth element of the single link list
public:
    sLinkList();
    ~sLinkList()
    {
        clear();
        delete head;
    }
    int length() const {return currentLength;}
    void clear();
    void insert(const elemType &x, int i);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    void erase(int i);
};
#endif
