//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "unit.h"

//функции обработки матрицы построчно
int NumZerosOneLine(int const x[], int n) {
    int result_i = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) {
            result_i++;
        }
    }
    return result_i;
}

int NumZerosLines(int const x[][NMAX], int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        result += NumZerosOneLine(x[i], n);
    }
    return result;
}

int NumZerosOneLine(int const* x, int n) {
    int result_i = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) {
            result_i++;
        }
    }
    return result_i;
}

int NumZerosLines(int const** x, int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        result += NumZerosOneLine(x[i], n);
    }
    return result;
}

int Multiplication(int const x[], int n) { //произведение ненулевых элементов в массиве static
    int result = 0;
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            if (first) { //возможен случай, когда вся строчка состоит из нулей
                result = 1;
                --first;
            }
            result *= x[i];
        }
    }
    return result;
}

int Multiplication(int const* x, int n) { //произведение ненулевых элементов в массиве dyn
    int result = 0;
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            if (first) { //возможен случай, когда вся строчка состоит из нулей
                result = 1;
                --first;
            }
            result *= x[i];
        }
    }
    return result;
}