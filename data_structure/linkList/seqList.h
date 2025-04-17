//
//  Seqlist.h
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//

#ifndef SEQLIST_H
#define SEQLIST_H

#include "list.h"
template <typename elemType>
class seqList: public list<elemType>
{
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initSize = 10);
    virtual ~seqList();
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0;
    virtual elemType visit(int i) const = 0;
    virtual void traverse() const;
    void erase(int i);
};
#endif
