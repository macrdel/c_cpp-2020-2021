//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#pragma once
#include "NMAX.h"

int** AllocMatrix(int m, int n);

void FreeMatrix(int**& x, int m);

int NumZerosMatrix(int** x, int m, int n);

void Multiplication(int** x, int*& y, int m, int n);

void OutputResultByLine(int* y, int m, char c);

void OutputResultByLine(int* y, int m, char c, FILE* f);

int NumZerosOneLine(int* x, int n);

int NumZerosLines(int** x, int m, int n);

int Multiplication(int* x, int n);

void OutputResultByLine(int** x, int m, int n, char c);

void OutputResultByLine(int** x, int m, int n, char c, FILE* file);

void OutputMatrix(int** x, int m, int n, char c);

void OutputMatrix(int** x, int m, int n, char c, FILE* file);

int InputMN(int& m, int& n, char c);

int InputMN(int& m, int& n, char* fname, FILE* file);

void MatrixInput(int**& x, int m, int n, char c);

int MatrixInput(int**& x, int m, int n, char* fname, FILE* file);

void OutputMas(int* x, int n, char c); //вывод массива в консоль

void OutputMas(int* x, int n, char c, FILE* f); //вывод массива в файл