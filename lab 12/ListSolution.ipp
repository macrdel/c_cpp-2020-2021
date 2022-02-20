//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_LISTSOLUTION_IPP
#define TEMPLATES_LISTSOLUTION_IPP
#include "ListSolution.h"

template<typename TInfo>
LSolution<TInfo>::LSolution(): List<TInfo>() { }

template<typename TInfo>
LSolution<TInfo>::LSolution(const List<TInfo> & ob, double _t): t(_t), List<TInfo>(ob) { }

template<typename TInfo>
LSolution<TInfo>::LSolution(const List<TInfo> & ob): List<TInfo>(ob) { }

template<typename TInfo>
bool LSolution<TInfo>::MinElement() {  // поиск и проверка на минимального элемента
    this->MoveNext(0);
    TInfo min = this->CurGetValue();
    while (!this->CurIsNullptr()) {
       TInfo tmp = this->CurGetValue();
       if (tmp < min)
           min = tmp;
       this->MoveNext(1);
    }
    return min > 0;
}

template<typename TInfo>
bool LSolution<TInfo>::Even() {
    this->MoveNext(0);
    TInfo num;
    bool flag = false;
    while (!this->CurIsNullptr() && !flag) {
        num = this->CurGetValue();
        flag = num % 2 == 0;
        this->MoveNext(1);
    }
    return flag;
}

template<typename TInfo>
LSolution<TInfo> &LSolution<TInfo>::DeletePositiveElements() {
    this->MoveNext(0);
    while (!this->CurIsNullptr())
        if (this->CurGetValue() > 0)
            this->DeleteCurrent(); // указатель cur изменяется внутри метода
        else
            this->MoveNext(1);
    return *this;
}

template<typename TInfo>
LSolution<TInfo> &LSolution<TInfo>::DeleteLessTElements() {
    this->MoveNext(0);
    while (!this->CurIsNullptr())
        if (this->CurGetValue() < t)
            this->DeleteCurrent(); // указатель cur изменяется внутри метода
        else
            this->MoveNext(1);
    return *this;
}

template<typename TInfo>
std::istream &operator>>(std::istream &is, List<TInfo> &l) {
    int n;
    TInfo tmp;
    is >> n;
    for (int i = 0; i < n; i++) {
        is >> tmp;
        l.AddToBegin(tmp);
    }
    return is;
}

template<typename TInfo>
std::ostream &operator<<(std::ostream &os, List<TInfo> &l) {
    l.MoveNext(0);
    while (!l.CurIsNullptr()) {        // идём вперёд
        os << l.CurGetValue() << " ";
        l.MoveNext(1);
    }
    os << "\n";
    l.MovePrev(0);
    while (!l.CurIsNullptr()) {          // идём обратно
        os << l.CurGetValue() << " ";
        l.MovePrev(1);
    }
    return os << "\n";
}

#endif //TEMPLATES_LISTSOLUTION_IPP