//
//  memory.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/19.
//
#ifndef MEMORY_H
#define MEMORY_H
class memory
{
private:
    struce node
    {
        int start, end; //指示分配空间的首尾位置
        node *prev, *next;
        node(int s, int e, node* prev = nullptr, node* next = nullptr): start(s), end(e), prev(prev), next(next){}
        node(){prev = nullptr; next = nullptr;}
    }
    node *head, *tail;
    
public:
    memory(int capacity); //开辟一个完整的空闲空间
    int malloc(int size); //申请大小为size的空间，并返回地址
    void free(int start, int size); //从start开始释放大小为size的空间
    ～memory();
};

memory::memory(int capacity)
{
    head = new node;
    head->next = new node(0, capacity - 1, head);
    head->next->next = tail = new node;
    tail->prev = head->next;
}

memory::~memory()
{
    node *p = head, *q;
    while(p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

int memory::malloc(int size)
{
    node *p = head->next;
    int returnValue;
    while(p != tail && p->end - p->start + 1 < size)
    {
        p = p->next;
    }
    if(p == tail)
    {
        return -1; //没有找到
    }
    returnValue = p->start; //记录起始位置
    if(p->end - p->start + 1 == size) //p的大小恰好为size，将p删掉
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    else //p的大小小于size
    {
        p->start += size;
    }
    return returnValue;
}

void memory::free(int start, int size)
{
    node *p = head->next, *np;
    
    //找到比start大的第一个节点
    while(p != tail && p->start < start)
    {
        p = p->next;
    }
    
    //判断释放空间能够和下一个节点(当前p指向的位置）连成一个空间
    if(p != tail && start + size == p-start)
    {
        p->start = start; //将两个空间连在一起
        np = p;
    }
    else
    {
        //无法连续则创建新节点
        np = new node(start, start + size - 1, p->prev, p);
        //将新节点插入到链表中
        p->prev->next = np;
        p->prev = np;
    }
    
    //判断np能否与前一个节点连成一个空间
    p = np->prev;
    if(p->end + 1 = np->start)
    {
        p->end = np->end;
        p->next = np->next;
        np->next->prev = p;
        delete np;
    }
}

#endif
