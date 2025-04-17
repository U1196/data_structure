//
//  list.h
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename elemType>
class list
{
public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0;
    virtual elemType visit(int i) const = 0;
    virtual void traverse() const;
    virtual ~list(){};
};
#endif
