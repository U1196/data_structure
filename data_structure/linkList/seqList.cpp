//
//  seqList.cpp
//  data_structure
//
//  Created by Fushimi on 2025/3/15.
//
#include "list.h"
#include "seqList.h"
#include "iostream"

using namespace std;

template <typename elemType>
seqList<elemType>::~seqList()
{
    delete[] data;
}

template <typename elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template <typename elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <typename elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template <typename elemType>
void seqList<elemType>::traverse()const
{
    cout << endl;
    for(int i = 0; i < currentLength; i++)
    {
        cout << data[i] << ' ';
    }
}

template <typename elemType>
seqList<elemType>::seqList(int initSize)
{
    maxSize = initSize;
    data = new elemType[initSize];
    currentLength = 0;
}

template <typename elemType>
int seqList<elemType>::search(const elemType &x)const
{
    int i;
    for(i = 0; i < currentLength && data[i] != x; ++i);
    if(i == currentLength)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template <typename elemType>
void seqList<elemType>::doubleSpace()
{
    elemType* tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i = 0; i < currentLength; ++i)
    {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

template <typename elemType>
void seqList<elemType>::insert(int i, const elemType& x)
{
    if(currentLength == maxSize)
    {
        doubleSpace();
    }
    for(int j = currentLength; j > i; --j)
    {
        data[j] = data[j - 1];
    }
    data[i] = x;
    ++currentLength;
}

template <typename elemType>
void seqList<elemType>::remove(int i)
{
    for(int j = i; j < currentLength - 1; --j)
    {
        data[j] = data[j + 1];
    }
    --currentLength;
}

template <typename elemType>
void seqList<elemType>::erase(int i)
{
    int cnt = 0;
    elemType tmp = data[i];
    for(int j = 0; j < currentLength; j++)
    {
        if(data[j] == tmp)
        {
            ++cnt;
        }
        else
        {
            data[j - cnt] = data[j];
        }
    }
    currentLength -= cnt;
}
