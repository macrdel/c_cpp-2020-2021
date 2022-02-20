//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_QUEUESOLUTION_IPP
#define TEMPLATES_QUEUESOLUTION_IPP
#include "QueueSolution.h"

template<typename TInfo>
QSolution<TInfo>::QSolution(): Queue<TInfo>() { }

template<typename TInfo>
QSolution<TInfo>::QSolution(const Queue<TInfo>& q): Queue<TInfo>(q) { }

template<typename TInfo>
QSolution<TInfo>::QSolution(const Queue<TInfo>& q, double _t): t(_t), Queue<TInfo>(q) { }

template<typename TInfo>
bool QSolution<TInfo>::IsEven(TInfo num) const {
    return num % 2 == 0;
}

template<typename TInfo>
bool QSolution<TInfo>::IsLessT(TInfo cur) const {
    return cur < t;
}

template<typename TInfo>
QSolution<TInfo>& QSolution<TInfo>::SplitByCondition(ptr comp)
{
    Queue<TInfo> dop;                 // дополнительная очередь
    int n = this->C();
    TInfo tmp;                        // промежуточный элемент
    while (n-- != 0) {
        tmp = this->Front();
        if ((this->*comp)(tmp))       // если условие comp выполнено
            this->Push(tmp);          // элемент добавляем в текущую очередь
        else
            dop.Push(tmp);            // иначе в дополнительную
        this->Pop();                  // из текущей очереди удаляем элемент впереди
    }
    while (!dop.IsEmpty()) {
        tmp = dop.Front();
        this->Push(tmp);              // в текущую добавляем элементы из дополнительной
        dop.Pop();
    }
    return *this;
}

template<typename TInfo>
std::ostream &operator<<(std::ostream &os, const Queue<TInfo> &q) {
    if (!q.IsEmpty()) {
        Queue<TInfo> cq = q;
        TInfo tmp;
        while (!cq.IsEmpty()) {
            tmp = cq.Front();
            cq.Pop();
            os << tmp << " ";
        }
        os << "\n";
        return os;
    }
    else
        throw EmptyQ();
}

template<typename TInfo>
std::istream &operator>>(std::istream &is, Queue<TInfo> &q) {
    int n;
    TInfo tmp;
    is >> n;
    for (int i = 0; i < n; i++) {
        is >> tmp;
        q.Push(tmp);
    }
    return is;
}


#endif //TEMPLATES_QUEUESOLUTION_IPP