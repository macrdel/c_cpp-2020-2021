//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_LIST_IPP
#define TEMPLATES_LIST_IPP
#include "List.h"

template<typename TInfo>
List<TInfo>::List() {
    this->first = nullptr;
    this->last = nullptr;
    this->cur = nullptr;
}

template<typename TInfo>
List<TInfo>::List(const List & ob) { // конструктор копирования
    if (ob.first != nullptr) {
        this->first = nullptr;
        this->last = nullptr;
        this->cur = nullptr;
        TElem<TInfo> *p = ob.first;
        while (p != nullptr) {
            this->AddToEnd(p->data);
            p = p->next;
        }
    }
    else
        throw EmptyL();
}

template<typename TInfo>
List<TInfo>::~List() {
    cur = this->first;
    while (cur != nullptr) {
        this->DeleteFirst();
    }
    this->last = nullptr;
}

template<typename TInfo>
bool List<TInfo>::IsEmpty() const {
    return this->first == nullptr;
}

template<typename TInfo>
void List<TInfo>::AddToBegin(TInfo t) {
    TElem<TInfo>* p = new TElem<TInfo>;
    p->data = t;
    p->next = this->first;
    p->prev = nullptr;
    if (this->first == nullptr) { // список пуст
        this->first = p;
        this->last = p;
    }
    else {                        // есть хотя бы один элемент
        this->first->prev = p;
        this->first = p;
    }
   return;
}

template<typename TInfo>
void List<TInfo>::AddToEnd(TInfo t) {
    TElem<TInfo>* p = new TElem<TInfo>;
    p->data = t;
    p->next = nullptr;
    p->prev = this->last;
    if (this->last == nullptr) { // список пуст
        this->first = p;
        this->last = p;
    }
    else {                        // есть хотя бы один элемент
        this->last->next = p;
        this->last = p;
    }
    return;
}

template<typename TInfo>
void List<TInfo>::DeleteFirst() {
    if (this->first != nullptr) {
        if (this->last == this->first) {       //единственный элемент
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            this->cur = nullptr;
        }
        else {                        // элемент не единственный
            TElem<TInfo>* p = this->first;
            this->first = this->first->next;
            this->first->prev = nullptr;
            delete p;
        }
       return;
    }
    else
        throw EmptyL();
}

template<typename TInfo>
void List<TInfo>::DeleteLast() {
    if (this->last != nullptr) {
        if (this->last == this->first) {         // единственный элемент
            delete this->last;
            this->first = nullptr;
            this->last = nullptr;
        }
        else {                         // элемент не единственный
            TElem<TInfo>* p = this->last;
            this->last = this->last->prev;
            this->last->next = nullptr;
            delete p;
        }
        return;
    }
    else
        throw EmptyL();
}

template<typename TInfo>
void List<TInfo>::AddAfterCurrent(TElem<TInfo> * cur, TInfo t) {
    if (cur != nullptr) {
        TElem<TInfo> * p = new TElem<TInfo>;
        p->data = t;
        if (cur == this->last) {  // если заданный элемент - последний
            p->next = nullptr;
            p->prev = this->last;
            this->last->next = p;
            this->last = p;
        }
        else {                      //cur <-> p <-> cur->next
            cur->next->prev = p;
            p->next = cur->next;
            p->prev = cur;
            cur->next = p;
        }
       return;
    }
    else
        throw EmptyPointerAdd();
}

template<typename TInfo>
void List<TInfo>::AddBeforeCurrent(TElem<TInfo> * cur, TInfo t) {
    if (cur != nullptr) {
        TElem<TInfo>* p = new TElem<TInfo>;
        p->data = t;
        if (cur == this->first) {  // если заданный элемент - первый
            p->prev = nullptr;
            p->next = this->first;
            this->first->prev = p;
            this->first = p;
        }
        else {                      //cur->prev <-> p <-> cur
            cur->prev->next = p;
            p->prev = cur->prev;
            p->next = cur;
            cur->prev = p;
        }
       return;
    }
    else
        throw EmptyPointerAdd();
}

template<typename TInfo>
void List<TInfo>::DeleteCurrent() {
    if (this->first == nullptr) // очередь пуста
        throw EmptyL();
    if (cur == nullptr)
        throw EmptyPointerAdd();
    if (cur == this->first && this->first == this->last) {       // единственный элемент
        delete cur;
        this->first = nullptr;
        this->last = nullptr;
        cur = nullptr;
    }
    else if (cur == this->first) {                               // удаляем первый
        this->first = this->first->next;
        this->first->prev = nullptr;
        delete cur;
        cur = this->first;
    }
    else if (cur == this->last) {                                // удаляем последний
        this->last = this->last->prev;
        this->last->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    else {                                      // удаляем из середины cur->prev <-> cur <-> cur->next
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        TElem<TInfo>* p = cur->next;
        delete cur;
        cur = p;
    }
    return;
}

template<typename TInfo>
void List<TInfo>::MoveNext(int i)
{
    if (i == 0)
        this->cur = this->first;
    else
        this->cur = this->cur->next;
}

template<typename TInfo>
void List<TInfo>::MovePrev(int i)
{
    if (i == 0)
        this->cur = this->last;
    else
        this->cur = this->cur->prev;
}

template<typename TInfo>
inline bool List<TInfo>::CurIsNullptr() const
{
    return this->cur == nullptr;
}

template<typename TInfo>
inline TInfo List<TInfo>::CurGetValue() const
{
    return this->cur->data;
}

#endif //TEMPLATES_LIST_IPP