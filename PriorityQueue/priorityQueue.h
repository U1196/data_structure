//
//  priorityQueue.h
//  data_structure
//
//  Created by Fushimi on 2025/4/17.
//
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "queue.h"
template<typename T>
class priQueue:public queue<T>
{
public:
    priQueue(int capacity = 100);
    priQueue(const T data[], int size);
    ~priQueue();
    bool isEmpty() const;
    void enQueue(const T &x);
    T deQueue();
    T getHead() const;
private:
    int currentSize;
    T *array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};
#endif

