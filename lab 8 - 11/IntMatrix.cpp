#include "IntMatrix.h"
#include "exception.h"

void IntMassive::Alloc(int _n) {
	Row = new int[_n];
	n = _n;
	return;
}

IntMassive::~IntMassive() {
	delete[] Row;
	n = 0;
}

int& IntMassive::operator[](int i) {
	// TODO: вставьте здесь оператор return
	if (i < n)
		return Row[i];
	else
		throw BadRightIndexException(i);
}

const int& IntMassive::operator[](int i) const {
	// TODO: вставьте здесь оператор return
	if (i < n)
		return Row[i];
	else
		throw BadRightIndexException(i);
}

//IntMatrix::IntMatrix(int m, int n) {
//	if (m >= 0 && n >= 0) {
//		if (m != 0 && n != 0) {
//			if (n == -1) {
//				rows = 1;
//				columns = 1;
//			}
//			else {
//				rows = m;
//				columns = n;
//			}
//			Matrix = new IntMassive[rows];
//			for (int i = 0; i < rows; i++)
//				Matrix[i].Alloc(columns);
//			if (n != -1 || m == -1) {
//				for (int i = 0; i < rows; i++)
//					for (int j = 0; j < columns; j++)
//						Matrix[i][j] = 0;
//			}
//			else
//				Matrix[0][0] = m;
//		}
//		else {
//			Matrix = NULL;
//			rows = 0;
//			columns = 0;
//		}
//	}
//	else
//		throw BadDimensionException(m, n);
//}

IntMatrix::IntMatrix(int m, int n) : Matrix(NULL), rows(m), columns(n) {
	if (rows >= 0 && columns >= 0) {
		if (rows != 0 && columns != 0) {
			Matrix = new IntMassive[rows];
			for (int i = 0; i < rows; i++)
				Matrix[i].Alloc(columns);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < columns; j++)
						Matrix[i][j] = 0;
		}
		else {
			rows = 0;
			columns = 0;
		}
	}
	else {
		throw BadDimensionException(rows, columns);
	}
}

IntMatrix::IntMatrix(int h): rows(1), columns(1){
	Matrix = new IntMassive[rows];
	Matrix[0].Alloc(columns);
	Matrix[0][0] = h;
}

IntMatrix::IntMatrix(const IntMatrix& ob, int t): rows(ob.rows), columns(ob.columns) {
	if (ob.Matrix != NULL) {
		Matrix = new IntMassive[rows];
		for (int i = 0; i < rows; i++)
			Matrix[i].Alloc(columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				Matrix[i][j] = ob.Matrix[i][j] + t;
	}
	else
		Matrix = NULL;
}

IntMatrix::~IntMatrix() {
	if (Matrix != NULL) 
		delete[] Matrix;
	rows = 0;
	columns = 0;
}

IntMatrix::operator double() const {
	double res = 0;
	int rc = rows * columns;
	if (rc != 0) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				res += Matrix[i][j];
		res /= rc;
		return res;
	}
	else
		throw EmptyMatrixException();
}

int IntMatrix::GetRowSize() const {
	return rows;
}

int IntMatrix::GetColumnSize() const {
	return columns;
}

int IntMatrix::GetElement(int i, int j) const {
	if (i < rows && j < columns)
		return Matrix[i][j];
	else if (i >= rows)
		throw BadLeftIndexException(i);
	else
		throw BadRightIndexException(j);
}

IntMassive& IntMatrix::operator[](int i) {
	// TODO: вставьте здесь оператор return
	if (i < rows)
	return Matrix[i];
	else
		throw BadLeftIndexException(i);
}


const IntMassive& IntMatrix::operator[](int i) const {
	// TODO: вставьте здесь оператор return
	if (i < rows)
	return Matrix[i];
	else
		throw BadLeftIndexException(i);
}

IntMatrix& IntMatrix::operator=(const IntMatrix& ob) {
	// TODO: вставьте здесь оператор return
	if (rows != ob.GetRowSize() || columns != ob.GetColumnSize()) {
		delete[] Matrix; //освобождение памяти в левом операнде
		//выделение памяти в левом операнде
		rows = ob.GetRowSize();
		columns = ob.GetColumnSize();
		Matrix = new IntMassive[rows];
		for (int i = 0; i < rows; i++)
			Matrix[i].Alloc(columns);
	}
	//копирование данных правого операнда в левый
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			Matrix[i][j] = ob[i][j];
	return *this;
}

//bool IntMatrix::operator<(const IntMatrix& ob) const {
//	double d1 = this->operator double();
//	double d2 = double(ob);
//	return d1 < d2;
//}
//
//bool IntMatrix::operator<=(const IntMatrix& ob) const {
//	double d1 = this->operator double();
//	double d2 = double(ob);
//	return d1 <= d2;
//}
//
//bool IntMatrix::operator>(const IntMatrix& ob) const {
//	double d1 = this->operator double();
//	double d2 = double(ob);
//	return d1 > d2;
//}
//
//bool IntMatrix::operator>=(const IntMatrix& ob) const {
//	double d1 = this->operator double();
//	double d2 = double(ob);
//	return d1 >= d2;
//}

//bool IntMatrix::operator==(const IntMatrix& ob) const {
//	bool flag = rows == ob.GetRowSize() && columns == ob.GetColumnSize();
//	if (flag) {
//		for (int i = 0; i < rows && flag; i++)
//			for (int j = 0; j < columns && flag; j++)
//				flag = Matrix[i][j] == ob[i][j];
//	}
//	return flag;
//}
//
//bool IntMatrix::operator!=(const IntMatrix& ob) const {
//	bool flag = rows != ob.GetRowSize() || columns != ob.GetColumnSize();
//	if (!flag) {
//		for (int i = 0; i < rows && !flag; i++)
//			for (int j = 0; j < columns && !flag; j++)
//				flag = Matrix[i][j] != ob[i][j];
//	}
//	return flag;
//}

//IntMatrix IntMatrix::operator+(const IntMatrix& ob) {
//	IntMatrix Sum(ob.GetRowSize(), ob.GetColumnSize());
//	for (int i = 0; i < ob.GetRowSize(); i++)
//		for (int j = 0; j < ob.GetColumnSize(); j++)
//			Sum[i][j] = Matrix[i][j] + ob[i][j];
//	return Sum;
//}
//
//IntMatrix IntMatrix::operator-(const IntMatrix& ob) {
//	IntMatrix Dif(ob.GetRowSize(), ob.GetColumnSize());
//	for (int i = 0; i < ob.GetRowSize(); i++)
//		for (int j = 0; j < ob.GetColumnSize(); j++)
//			Dif[i][j] = Matrix[i][j] - ob[i][j];
//	return Dif;
//}

IntMatrix& IntMatrix::operator+=(int t) {
	// TODO: вставьте здесь оператор return
	if (this != NULL) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				Matrix[i][j] += t;
		return *this;
	}
	else
		throw EmptyMatrixException();
}

IntMatrix& IntMatrix::operator-=(int t) {
	// TODO: вставьте здесь оператор return
	if (this != NULL) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				Matrix[i][j] -= t;
		return *this;
	}
	else
		throw EmptyMatrixException();
}