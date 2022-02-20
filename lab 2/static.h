//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#pragma once
#include "NMAX.h"

int NumZerosMatrix(const int x[][NMAX], int m, int n);

void Multiplication(const int x[][NMAX], int y[], int m, int n);

void OutputResultByLine(const int y[], int m, char c);

void OutputResultByLine(const int y[], int m, char c, FILE* f);

int NumZerosOneLine(const int x[], int n);

int NumZerosLines(const int x[][NMAX], int m, int n);

int Multiplication(const int x[], int n);

void OutputResultByLine(const int x[][NMAX], int m, int n, char c);

void OutputResultByLine(const int x[][NMAX], int m, int n, char c, FILE* file);

void OutputMatrix(const int x[][NMAX], int m, int n, char c);

void OutputMatrix(const int x[][NMAX], int m, int n, char c, FILE* file);

int MatrixInput(int x[][NMAX], int& m, int& n, char* fname);

int MatrixInput(int x[][NMAX], int& m, int& n, char c);

void OutputMas(const int x[], int n, char c, FILE* f); //вывод массива в файл

void OutputMas(const int x[], int n, char c); //вывод массива в консоль