#pragma once
#include <cstdio>

class Exception { //иерархия исключений, базовый абстрактный класс
public:
	virtual void Message() = 0; //чисто виртуальный метод вывода сообщений об ошибке
};

class BadLeftIndexException : public Exception { //обращение к несуществующему элементу матрицы
private:
	int i;
public:
	BadLeftIndexException(int _i) : i(_i) { }
	void Message();
};

class BadRightIndexException : public Exception { //обращение к несуществующему элементу матрицы
private:
	int j;
public:
	BadRightIndexException(int _j) : j(_j) { }
	void Message();
};

class BadDimensionException : public Exception { //неправильное задание размера
private:
	int m, n;
public:
	BadDimensionException(int _m, int _n) : m(_m), n(_n) { }
	void Message();
};

class DimensionSumException : public Exception { //исключение при сложении/вычитании/сравнении
private:
	int m1, n1, m2, n2;
public:
	DimensionSumException(int _m1, int _n1, int _m2, int _n2) : m1(_m1), n1(_n1), m2(_m2), n2(_n2) { }
	void Message();
};

class DimensionComposException : public Exception { //исключение при умножении
private:
	int n1, m2;
public:
	DimensionComposException(int _n1, int _m2) : n1(_n1), m2(_m2) { }
	void Message();
};

class EmptyMatrixException : public Exception { //пустая матрица
	void Message();
};