//
//  binaryTree.h
//  data_structure
//
//  Created by Fushimi on 2025/4/3.
//
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "btree.h"
template <typename T>
class binaryTree: public bTree<T>
{
    friend void printTree(const binaryTree &t, T flag);

private:
    struct node
    {
        node *left, *right; //结点的左右儿子信息
        T data; //结点存储的信息
        
        node(): left(nullptr), right(nullptr){}
        node(T item, node *L = nullptr, node *R = nullptr): data(item), left(L), right(R){}
        ~node(){}
    };
    
    node *root; //用根结点确定一个二叉树
    
    node* find(T x, node *t) const;
    void clear(node* &t);
    void preOrder(node *t) const; //内层实现函数
    void midOrder(node *t) const;
    void postOrder(node *t) const;

public:
    binaryTree(): root(nullptr){}
    binaryTree(T x){root = new node(x);}
    virtual ~binaryTree();
    virtual void clear();
    virtual bool isEmpty() const;
    virtual T Root(T flag) const;
    virtual T parent(T x, T flag) const {return flag;} //二叉链表实现不处理父结点返回
    virtual T lchild(T x, T flag) const;
    virtual T rchild(T x, T flag) const;
    virtual void delLeft(T x);
    virtual void delRight(T x);
    virtual void preOrder() const; //外层包裹（用户不知道实现需要根结点）
    virtual void midOrder() const;
    virtual void postOrder() const;
    virtual void levelOrder() const;
    void createTree(T flag);
};
#endif
