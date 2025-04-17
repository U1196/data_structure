//
//  binaryTree.cpp
//  data_structure
//
//  Created by Fushimi on 2025/4/3.
//
#include <iostream>
#include "binaryTree.h"
#include "linkQueue.h"
using namespace std;

template <typename T>
bool binaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
T binaryTree<T>::Root(T flag) const
{
    if(!root)
    {
        return root->data;
    }
    else
    {
        return flag;
    }
}

template <typename T>
void binaryTree<T>::clear(binaryTree<T>::node* &t)
{
    if(t == nullptr)
    {
        return;
    }
    else
    {
        clear(t->right);
        clear(t->left);
        delete t;
        t = nullptr;
    }
}

template <typename T>
void binaryTree<T>::clear()
{
    clear(root);
}

template <typename T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template <typename T>
void binaryTree<T>::preOrder(binaryTree<T>::node* t) const
{
    if(t == nullptr)
    {
        return;
    }
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <typename T>
void binaryTree<T>::preOrder() const
{
    preOrder(root);
}


template <typename T>
void binaryTree<T>::midOrder(binaryTree<T>::node* t) const
{
    if(t == nullptr)
    {
        return;
    }
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t-right);
}

template <typename T>
void binaryTree<T>::midOrder() const
{
    midOrder(root);
}

template <typename T>
void binaryTree<T>::postOrder(binaryTree<T>::node* t) const
{
    if(t == nullptr)
    {
        return;
    }
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template <typename T>
void binaryTree<T>::postOrder() const
{
    postOrder(root);
}

template <typename T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<node*> que;
    node* tmp;
    que.enQueue(root);
    while(!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if(tmp->left)
            que.enQueue(tmp->left);
        if(tmp->right)
            que.enQueue(tmp->right);
    }
}

template <typename T>
binaryTree<T>::node* binaryTree<T>::find(T x, binaryTree<T>::node* t) const
{
    if(t == nullptr)
    {
        return nullptr;
    }
    node *tmp;
    if(t->data == x)
    {
        return t;
    }
    if((tmp = find(x, t->left)))
    {
        return tmp;
    }
    else
    {
        return find(x, t->right);
    }
}

template <typename T>
void binaryTree<T>::delLeft(T x)
{
    node *tmp = find(x, root);
    if(tmp == nullptr)
    {
        return;
    }
    clear(tmp->right); //tmp->right为nullptr的情况在clear中处理
}

template <typename T>
void binaryTree<T>::delRight(T x)
{
    node *tmp = find(x, root);
    if(tmp == nullptr)
    {
        return;
    }
    clear(tmp->right); //tmp->right为nullptr的情况在clear中处理
}

template <typename T>
T binaryTree<T>::lchild (T x, T flag) const
{
    node* tmp = find(x, root);
    if(tmp == nullptr || tmp->left == nullptr)
    {
        return flag;
    }
    else
    {
        return tmp->left->data;
    }
}

template <typename T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<node*> que;
    node* tmp;
    T data, ldata, rdata;
    //创建树，输入flag表示空
    cout << "输入根结点:";
    cin >> data;
    tmp = new node(data);
    que.enQueue(tmp);
    while(!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "输入" << tmp->data << "的两个儿子" << flag << "表示空结点";
        cin >> ldata >> rdata;
        if(ldata != flag)
        {
            que.enQueue(tmp->left = new node(ldata));
        }
        if(rdata != flag)
        {
            que.enQueue(tmp->right = new node(rdata));
        }
    }
}

template <typename T>
void printTree(const binaryTree<T> &t, T flag)
{
    linkQueue<T> que;
    que.enQueue(t.Root->data);
    char p, l ,r;
    while(!que.isEmpty())
    {
        p = que.deQueue();
        l = t.lchild(t, flag);
        r = t.rchild(t, flag);
        cout << p << '\t' << l << '\t' << t << '\n';
        if(l != flag)
        {
            que.enQueue(l);
        }
        if(r != flag)
        {
            que.deQueue(r);
        }
    }
}
