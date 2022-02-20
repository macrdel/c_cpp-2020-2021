//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "unit.h"

//обработка матрицы целиком
int NumZerosMatrix(int const x[][NMAX], int m, int n) { //подсчёт количества нулей матрицы статическая версия
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0)
                ++result;
        }
    }
    return result;
}

int NumZerosMatrix(int const** x, int m, int n) { //подсчёт количества нулей матрицы динамическая версия
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0)
                result++;
        }
    }
    return result;
}

void Multiplication(int const x[][NMAX], int y[], int m, int n) {
    for (int i = 0; i < m; i++) {
        int result_i = 0;
        bool first = true;
        for (int j = 0; j < n; j++) {
            if (x[i][j] != 0) {
                if (first) { //возможен случай нулевой строки
                    result_i = 1;
                    first = false;
                }
                result_i *= x[i][j];
            }
        }
        y[i] = result_i;
    }
    return;
}

void Multiplication(int const** x, int*& y, int m, int n) { 
    for (int i = 0; i < m; i++) {
        int result_i = 0;
        bool first = true;
        for (int j = 0; j < n; j++) {
            if (x[i][j] != 0) {
                if (first) { //возможен случай нулевой строки
                    result_i = 1;
                    first = false;
                }
                result_i *= x[i][j];
            }
        }
        y[i] = result_i;
    }
    return;
}