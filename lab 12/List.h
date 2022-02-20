//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_LIST_H
#define TEMPLATES_LIST_H
#include "Exception.h"

template<typename TInfo>
struct TElem {
    TInfo data;           // информационная часть
    TElem *next, *prev;   // указатели на следующий и предыдущий
};

template<typename TInfo>
class List {
private:

    TElem<TInfo> *first, *last;  // указатели на первый и последний
    TElem<TInfo> *cur;           // указатель на текущий элемент для итерирования
public:

    List();
    List(const List&);
    ~List();
    bool IsEmpty() const;
    void AddToBegin(TInfo);
    void AddToEnd(TInfo);
    void AddAfterCurrent(TElem<TInfo>*, TInfo);
    void AddBeforeCurrent(TElem<TInfo>*, TInfo);
    void DeleteFirst();
    void DeleteLast();
    void DeleteCurrent();

    void MoveNext(int i);
    void MovePrev(int i);
    bool CurIsNullptr() const;
    TInfo CurGetValue() const;

};

#include "List.ipp"
#endif //TEMPLATES_LIST_H
