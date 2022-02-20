//#include "QueueSolution.h"
#include "ListSolution.h"

/*
1. Создать структуру из целых чисел. Разделить её содержимое на чётные и нечётные числа.
2. Создать структуру из вещественных чисел. Разделить её содержимое на числа, меньшие заданного числа
 и не меньшие заданного числа.
*/

/*int main() {

    std::cout << "QUEUE\nTask 1\n";
    Queue<int> q1;
    std::cout << "Enter int QUEUE for first task\n";
    std::cin >> q1;                                             // вводим целочисленную очередь
    std::cout << "int QUEUE before change\n";
    std::cout << q1;                                            // выводим её
    QSolution<int>::ptr f1 = &QSolution<int>::IsEven;           // объявляем и определяем указатель
                                                                // на метод класса QSolution проверки на чётность числа
    QSolution<int> qs1 = q1;
    qs1.SplitByCondition(f1);                                   // разделяем очередь на чётные и нечётные,
                                                                // передаём в метод указатель на метод проверки на чётность
    std::cout << "int QUEUE after change\n" << qs1 << "\n\n";

    std::cout <<"\n\nTask2\n";
    float k;
    std::cout << "Enter float for task 2\n";
    std::cin >> k;
    Queue<float> q2;
    std::cout << "Enter float QUEUE for task 2\n";
    std::cin >> q2;
    std::cout << "Given float: " << k << "\n";
    std::cout << "float QUEUE before change\n" << q2;
    QSolution<float>::ptr f2 = &QSolution<float>::IsLessT;
    QSolution<float> qs2(q2, k);
    qs2.SplitByCondition(f2);
    std::cout << "float QUEUE after change\n" << qs2 << "\n\n";

    return 0;
}*/

/*
1.  Если в списке из вещественных чисел минимальный элемент положителен,
    удалить из списка элементы, меньшие заданного числа.
2.  Если в списке из целых чисел есть чётные элементы, удалить из списка положительные элементы.
*/


int main() {

    std::cout << "LIST\nTask 1\n";
    List<float> l1;
    std::cout << "Enter FLOAT list for first task\n";
    std::cin >> l1;
    std::cout << "float LIST before change\n" << l1;
    std::cout << "Enter float for first task\n";
    float k;
    std::cin >> k;
    std::cout << "Given float: " << k << "\n";
    LSolution<float> ls1(l1, k);
    if (ls1.MinElement()) {
        ls1.DeleteLessTElements();
        std::cout << "float LIST after change\n" << ls1;
    }
    else
        std::cout << "min element in LIST is negative, bye\n";


    std::cout << "Task 2\n";
    List<int> l2;
    std::cout << "Enter int list for first task\n";
    std::cin >> l2;
    std::cout << "int LIST before change\n" << l2;
    LSolution<int> ls2(l2);
    if (ls2.Even()) {
        ls2.DeletePositiveElements();
        std::cout << "int LIST after change\n" << ls2;
    }
    else
        std::cout << "even numbers not excists in list, bye\n";

    return 0;
}
