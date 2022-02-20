//Определить в каком массиве больше количество элементов, больших заданного числа.
//Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.
#pragma once
#include <cstdio>
#include <locale.h>

const int nmax = 10; //максимальное количество элементов массива

int NumT(const int x[], int n, int t); //количество удовлетворяющий условию элементов

int ArrayInput(int x[], int& n, char* fname); //ввод из файла

int ArrayInput(int x[], int& n, char c); //ввод вручную

void OutputResult(int t, int ka, int kb, int kc); //вывод результата в консоль

void OutputMas(const int x[], int n, char c); //вывод массива в консоль

void OutputResultF(int t, int ka, int kb, int kc, FILE* f); //вывод результата в файл

void OutputMasF(const int x[], int n, char c, FILE* f); //вывод массива в файл