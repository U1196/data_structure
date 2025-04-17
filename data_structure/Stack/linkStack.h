//
//  linkStack.h
//  data_structure
//
//  Created by Fushimi on 2025/3/20.
//
#ifndef LINGSTACK_H
#define LINGSTACK_H
#include "newstack.h"

template <typename elemType>
class linkStack: public newstack<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(): next(nullptr){}
        node(const elemType &x, node *next = nullptr): data(x), next(next){}
        ~node(){}
    };
    node* top_p;
    
public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};
#endif
