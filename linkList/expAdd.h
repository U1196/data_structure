//
//  expAdd.h
//  data_structure
//
//  Created by Fushimi on 2025/3/19.
//
#ifndef EXPADD_H
#define EXPADD_H
class Node
{
public:
    int coff = 0, exp = 0;
    Node* next;
    
    Node(){next = nullptr;}
    Node(int n1, int n2, Node* next = nullptr): coff(n1), exp(n2), next(next){}
};

Node* add(Node *exp1, Node *exp2)
{
    Node *res, *p, *tmp;
    res = p = new Node(); //res保存头节点位置，p跟踪实现节点增加
    exp1 = exp1->next;
    exp2 = exp2->next;
    while(exp1 != nullptr && exp2 != nullptr)
    {
        if(exp1->exp > exp2->exp)
        {
            p->next = new Node(exp2->coff, exp2->exp);
            exp2 = exp2->next;
        }
        else if(exp1->exp < exp2->exp)
        {
            p->next = new Node(exp1->coff, exp1->exp);
            exp1 = exp1->next;
        }
        else if(exp1->coff + exp2->coff != 0)
        {
            p->next = new Node(exp1->coff + exp2->coff, exp2->exp);
            exp1 = exp1->next;
            exp2 = exp2->next;
        }
        p = p->next; //p一直指向最后一位
    }
    //将尚未结束的表达式并入结果表达式
    if(exp1 == nullptr)
    {
        tmp = exp2;
    }
    else if(exp2 == nullptr)
    {
        tmp = exp1;
    }
    else
    {
        return res; //如果两个表达式同时结束
    }
    while(tmp != nullptr)
    {
        p->next = new Node(tmp->coff, tmp->exp);
        tmp = tmp->next;
        p = p->next;
    }
    return res;
}
#endif
