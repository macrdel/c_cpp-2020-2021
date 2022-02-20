//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#pragma once
#include <cstdio>
#include <locale.h>

const int NMAX = 10;

int** AllocMatrix(int m, int n);

void FreeMatrix(int** x, int m);

int NumZerosMatrix(int const x[][NMAX], int m, int n);

int NumZerosMatrix(int const** x, int m, int n);

void Multiplication(int const x[][NMAX], int y[], int m, int n);

void Multiplication(int const** x, int*& y, int m, int n);

void OutputResultByLine(int const y[], int m, char c);

void OutputResultByLine(int const y[], int m, char c, FILE* f);

void OutputResultByLine(int const* y, int m, char c);

void OutputResultByLine(int const* y, int m, char c, FILE* f);

inline int NumZerosOneLine(int const x[], int n);

int NumZerosLines(int const x[][NMAX], int m, int n);

inline int NumZerosOneLine(int const* x, int n);

int NumZerosLines(int const** x, int m, int n);

inline int Multiplication(int const x[], int n);

inline int Multiplication(int const* x, int n);

void OutputResultByLine(int const x[][NMAX], int m, int n, char c);

void OutputResultByLine(int const x[][NMAX], int m, int n, char c, FILE* file);

void OutputResultByLine(int const** x, int m, int n, char c);

void OutputResultByLine(int const** x, int m, int n, char c, FILE* file);

void OutputMatrix(int const x[][NMAX], int m, int n, char c);

void OutputMatrix(int const x[][NMAX], int m, int n, char c, FILE* file);

void OutputMatrix(int const** x, int m, int n, char c);

void OutputMatrix(int const** x, int m, int n, char c, FILE* file);

int MatrixInput(int x[][NMAX], int& m, int& n, char* fname);

int MatrixInput(int x[][NMAX], int& m, int& n, char c);

int InputMN(int& m, int& n, char c);

int InputMN(int& m, int& n, char* fname, FILE* file);

void MatrixInput(int** x, int m, int n, char c);

int MatrixInput(int** x, int m, int n, char* fname, FILE* file);