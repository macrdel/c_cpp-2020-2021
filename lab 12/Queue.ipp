//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_QUEUE_IPP
#define TEMPLATES_QUEUE_IPP
#include "Queue.h"

template<typename TInfo>
Queue<TInfo>::Queue() {
   count = 0;
}

template<typename TInfo>
Queue<TInfo>::Queue (const Queue& ob): count(ob.count) {
    if (count > 0) {
        queue = new TInfo [count];
        for (int i = 0; i < count; i++)
            queue[i] = ob.queue[i];
    }
    else
        throw EmptyQ();
}

template<typename TInfo>
bool Queue<TInfo>::IsEmpty() const {
    return count == 0;
}

// добавление в конец очереди
template<typename TInfo>
void Queue<TInfo>::Push(TInfo info) {
    TInfo* queue_dop = queue;        // дополнительный массив
    queue = new TInfo [count + 1];   // дополнительное выделение памяти
    for (int i = 0; i < count; i++)  // дозапись существующих элементов
        queue[i] = queue_dop[i];
    queue[count++] = info;           // добавление последнего элемента и увеличение счётчика
    if (count > 1)
        delete[] queue_dop;
    return;
}

template<typename TInfo>
void Queue<TInfo>::Pop() {
    if (count > 0) {
        TInfo* queue_dop = new TInfo [--count]; // дополнительный массив на единицу меньше
                                                // уменьшаем счётчик
        for (int i = 0; i < count; i++)
            queue_dop[i] = queue[i + 1];        // в новый массив записываются все, кроме первого
        if (count > 0)
            delete[] queue;                     // освобождаем участок queue
        queue = queue_dop;
        return;
    }
    else {
        throw EmptyQ();
    }
}

template<typename TInfo>
TInfo Queue<TInfo>::Front() const {
    if (count > 0) {
        return queue[0];
    }
    else {
        throw EmptyQ();
    }
}

/*
template<typename TInfo>
[[maybe_unused]] TInfo Queue<TInfo>::Back() const {
    if (count > 0) {
        return queue[count - 1];
    }
    else {
        throw EmptyQ();
    }
}
*/

template<typename TInfo>
Queue<TInfo>::~Queue() {
    if (count > 0) {
        delete[] queue;
    }
}

/*template<typename TInfo>
void Queue<TInfo>::Print() const {
    for (int i = 0; i < count; i++)
        std::cout << queue[i] << "\n";
    std::cout << "\n";
    return;
}*/

/*template<typename TInfo>
void Queue<TInfo>::TopToBottom(Queue<TInfo>& ob ) {
    if (count != 0) {
        TInfo tmp = this->Front();
        this->Pop();
        ob.Push(tmp);
    }
    else
        throw EmptyQ();
}*/

template<typename TInfo>
int Queue<TInfo>::C() const {
    return count;
}


#endif //TEMPLATES_QUEUE_IPP