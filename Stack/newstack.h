//
//  stack.h
//  data_structure
//
//  Created by Fushimi on 2025/3/20.
//
#ifndef STACK_H
#define STACK_H
template <typename elemType>
class newstack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0; //进栈
    virtual elemType pop() = 0; //出栈
    virtual elemType top() const = 0; //取栈顶元素
    virtual ~newstack(){}
};
#endif
