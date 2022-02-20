//
// Created by user on xx.xx.2020.
//

#ifndef TEMPLATES_LISTSOLUTION_H
#define TEMPLATES_LISTSOLUTION_H
#include <iostream>
#include "List.h"

/*1.  Если в списке из вещественных чисел минимальный элемент положителен,
    удалить из списка элементы, меньшие заданного числа.
2.  Если в списке из целых чисел есть чётные элементы, удалить из списка положительные элементы.*/

template<typename TInfo>
class LSolution: public List<TInfo> {
private:
    const double t = 0.0;                       // заданное число для первого задания
public:
    LSolution();
    LSolution(const List<TInfo>&);
    LSolution(const List<TInfo>&, double _t);
    bool MinElement();                          // поиск и проверка на положительность минимального числа (1 задание)
    bool Even();                                // поиск и проверка на наличие чётного числа (2 задание)
    LSolution<TInfo>& DeletePositiveElements(); // удаление положительных элементов (2 задание)
    LSolution<TInfo>& DeleteLessTElements();    // удаление элементов, меньших t (1 задание)
};

template<typename TInfo>
std::istream& operator>> (std::istream& is, List<TInfo>& l); // ввод списка

template<typename TInfo>
std::ostream& operator<< (std::ostream& os, List<TInfo>& l); // вывод списка на экран


#include "ListSolution.ipp"
#endif //TEMPLATES_LISTSOLUTION_H