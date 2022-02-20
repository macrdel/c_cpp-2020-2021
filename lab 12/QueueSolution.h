//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_QUEUESOLUTION_H
#define TEMPLATES_QUEUESOLUTION_H
#include <iostream>
#include "Queue.h"

/*
1. Создать структуру из целых чисел. Разделить её содержимое на чётные и нечётные числа.
2. Создать структуру из вещественных чисел. Разделить её содержимое на числа, меньшие заданного числа
 и не меньшие заданного числа.
*/

template<typename TInfo>
class QSolution: public Queue<TInfo> {      // наследуемый от Queue шаблонный класс для решения поставленных задач
private:
    const double t = 0.0;                   // заданное число для второго задания
public:
    typedef bool (QSolution<TInfo>::*ptr) (TInfo) const; // указатель на логическую функцию-член класса
    QSolution();
    QSolution(const Queue<TInfo>&);
    QSolution(const Queue<TInfo>&, double _t);
    bool IsEven(TInfo) const;                        // проверка на чётность (1 задание)
    bool IsLessT(TInfo) const;                       // сравнение с t (2 задание)
    QSolution<TInfo>& SplitByCondition(ptr);         // метод деления очереди на две части по условию
                                                     // в качестве формального параметра - указатель на метод
                                                     // IsEven или IsLessT
};

template<typename TInfo>
std::ostream& operator<< (std::ostream& os, const Queue<TInfo>& q);   // вывод очереди

template<typename TInfo>
std::istream& operator>> (std::istream& is, Queue<TInfo>& q);         // ввод очереди

#include "QueueSolution.ipp"
#endif //TEMPLATES_QUEUESOLUTION_H 
