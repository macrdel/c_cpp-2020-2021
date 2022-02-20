#pragma once
#include <cstdio>

class IntMassive;
class IntMatrix;

class IntMassive {                                //тип строки матрицы
public:
	void Alloc(int);                              //инициализация - выделение места для строки
	~IntMassive();                                //деструктор
	int& operator[](int);                         //доступ к i-ому элементу строки
	const int& operator[](int) const;
private:
	int* Row;
	int n;
};

class IntMatrix {
public:
	//~8
	explicit IntMatrix(int m = 1, int n = 1);
	IntMatrix(int);
	IntMatrix(const IntMatrix& ob, int t = 0);     //конструктор копирования
	~IntMatrix();                                  //деструктор
	explicit operator double() const;                       //оператор преобразования из IntMatrix в double
	int GetRowSize() const;
	int GetColumnSize() const;
	int GetElement(int i, int j) const;
	//~9
	IntMassive& operator[](int);                   //элемент матрицы по индексам 
	const IntMassive& operator[](int) const;       
	IntMatrix& operator= (const IntMatrix& ob);    //операция присваивания
	//bool operator< (const IntMatrix& ob) const;    //сравнения как методы класса
	//bool operator<= (const IntMatrix& ob) const;
	//bool operator> (const IntMatrix& ob) const;
	//bool operator>= (const IntMatrix& ob) const;
	//bool operator== (const IntMatrix& ob) const;
	//bool operator!= (const IntMatrix& ob) const;
	//IntMatrix operator+ (const IntMatrix& ob);     //сложение и вычитание матриц
	//IntMatrix operator- (const IntMatrix& ob);
	IntMatrix& operator+= (int);                   //прибавление и вычитание из матриц заданного числа
	IntMatrix& operator-= (int);
	//~10
	friend IntMatrix operator+ (const IntMatrix& l, const IntMatrix& r);
	friend IntMatrix operator- (const IntMatrix& l, const IntMatrix& r);
	friend IntMatrix operator* (const IntMatrix& l, const IntMatrix& r);
	friend bool operator== (const IntMatrix& l, const IntMatrix& r);
	friend bool operator!= (const IntMatrix& l, const IntMatrix& r);
	friend bool operator< (const IntMatrix& l, const IntMatrix& r);
	friend bool operator<= (const IntMatrix& l, const IntMatrix& r);
	friend bool operator> (const IntMatrix& l, const IntMatrix& r);
	friend bool operator>= (const IntMatrix& l, const IntMatrix& r);
private:
	IntMassive* Matrix;
	int rows;
	int columns;
};