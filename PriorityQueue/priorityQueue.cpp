//
//  priorityQueue.cpp
//  data_structure
//
//  Created by Fushimi on 2025/4/17.
//
#include "priorityQueue.h"
template<typename T>
priQueue<T>::priQueue(int capacity = 100)
{
    array = new T[capacity];
    maxSize = capacity;
    currentSize = 0;
}

template<typename T>
priQueue<T>::~priQueue()
{
    delete[] array;
}

template<typename T>
bool priQueue<T>::isEmpty() const
{
    return currentSize == 0;
}

template<typename T>
T priQueue<T>::getHead() const
{
    return array[1];
}

template<typename T>
void priQueue<T>::enQueue(const T &x)
{
    if(currentSize == maxSize - 1)
    {
        doubleSpace();
    }
    //向上过滤
    int hole = currentSize + 1;
    for(; hole > 1 && x < array[hole / 2]; hole /= 2)
    {
        array[hole] = array[hole / 2];
    }
    array[hole] = x; //填入x
}

template<typename T>
T priQueue<T>::deQueue()
{
    T minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

template<typename T>
void priQueue<T>::percoalteDown(int hole)
{
    T tmp = array[hole];
    int child;
    for(; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if(child != currentSize && array[child] > array[child + 1])
        {
            ++child;
        }
        if(array[child] < tmp)
        {
            array[hole] = array[child];
        }
        else
        {
            break;
        }
    }
    array[hole] = tmp;
}
