//
//  1.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/26.
//
#include <iostream>
#include "seqStack.h"

using namespace std;

int FromIntSeqToPushPopSeq(const int intSeq[], int pushPopSeq[], int num);

int main()
{
    int *intSeq, *pushPopSeq, num, i, val;

    if (!(cin >> num) || num <= 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    intSeq = new int[num];
    pushPopSeq = new int[num + num];

    for (i = 0; i < num; i++)
    {
        if (!(cin >> val))
        {
            cout << "Invalid input" << endl;
            delete []intSeq;
            delete []pushPopSeq;
            return 0;
        }
        intSeq[i] = val;
    }
    
    if (FromIntSeqToPushPopSeq(intSeq, pushPopSeq, num))
    {
        cout << "no" << endl;
            for (i = 0, num += num; i < num; i++)
                cout << pushPopSeq[i];
            cout << endl;
    }
    else
    {
        cout << "yes" << endl;
        for (i = 0, num += num; i < num; i++)
            cout << pushPopSeq[i];
        cout << endl;
    }

    delete []intSeq;
    delete []pushPopSeq;
    
    return 0;
}

int FromIntSeqToPushPopSeq(const int intSeq[], int pushPopSeq[], int num)
{
    for(int i = 0; i < num; ++i)
    {
        if(intSeq[i] > num || intSeq[i] < 1)
        {
            return 1;
        }
    }
    int i = 1, j = 0, index = 0;
    seqStack<int> tmp(num);
    while(i <= num && i != intSeq[j])
    {
        tmp.push(i++);
        pushPopSeq[index++] = 1;
    } //i是intSeq[0]，但i没有被放入到栈中。
    int max = i;
    cout << max;
    pushPopSeq[index++] = 1;
    pushPopSeq[index++] = 0; //处理intSeq[0]的入栈和出栈
    ++i;
    for(j = 1; j < num; ++j)
    {
        if(intSeq[j] > max)
        {
            for(; i <= intSeq[j]; ++i)
            {
                tmp.push(i);
                pushPopSeq[index++] = 1;
            }
            pushPopSeq[index++] = 0;
            tmp.pop();
            max = intSeq[j];
        }
        else if(intSeq[j] == tmp.top())
        {
            tmp.pop();
            pushPopSeq[index++] = 0;
        }
        else
        {
            cout << 2;
            return 1;
        }
    }
    return 0;
}

