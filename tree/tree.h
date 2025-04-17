//
//  tree.h
//  data_structure
//
//  Created by Fushimi on 2025/3/31.
//

#ifndef TREE_H
#define TREE_H
template <typename T>
class tree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T child(T x, int i, T flag) const = 0;
    virtual void remove(T x, int i) = 0;
    virtual void traverse() const = 0;
};
#endif
