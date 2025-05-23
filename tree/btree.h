//
//  btree.h
//  data_structure
//
//  Created by Fushimi on 2025/3/31.
//
#ifndef BTREE_H
#define BTREE_H
template <typename T>
class bTree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0;
    virtual T rchild(T x, T flag) const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};
#endif
