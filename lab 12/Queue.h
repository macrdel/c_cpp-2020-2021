//
// Created by user on xx.xx.2020.
//
#ifndef TEMPLATES_QUEUE_H
#define TEMPLATES_QUEUE_H
#include "Exception.h"

template<typename TInfo>
class Queue {
private:
    TInfo* queue;        // массив
    int count;           // текущее количество элементов


public:
    Queue();
    Queue(const Queue&);
    ~Queue();
    bool IsEmpty() const;
    void Push(TInfo);
    void Pop();
    TInfo Front() const;
    int C() const;
   // [[maybe_unused]] TInfo Back() const;
    /* void Print() const;*/
   /*void TopToBottom(Queue<TInfo>&);*/
};

#include "Queue.ipp"
#endif //TEMPLATES_QUEUE_H