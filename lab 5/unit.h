//Определить в каком массиве больше количество элементов, больших заданного числа.
//Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.
#pragma once
#include "MathFu.h"
#include <cstdio>
#include <locale.h>

const int nmax = 10; //максимальное количество элементов массива

int NumT(double*& x, int n, int t, MF func); //количество удовлетворяющий условию элементов

int InputN(int& n, char* fname, FILE* file); //ввод из файла количества элементов

int InputN(int& n, char c); //ввод количества элементов вручную

int ArrayInput(double*& x, int n, char* fname, FILE* file); //ввод массива из файла

void ArrayInput(double*& x, int n, char c); //ввод массива вручную

void OutputResult(int t, int ka, int kb, int kc); //вывод результата в консоль

void OutputMas(double* x, int n, char c); //вывод массива в консоль

void OutputResultF(int t, int ka, int kb, int kc, FILE* f); //вывод результата в файл

void OutputMasF(double* x, int n, char c, FILE* f); //вывод массива в файл