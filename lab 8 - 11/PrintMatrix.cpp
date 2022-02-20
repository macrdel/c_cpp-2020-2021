#include "IntMatrix.h"
#include "PrintMatrix.h"
#include "exception.h"

IntMatrix operator+(const IntMatrix& l, const IntMatrix& r) {
	if (l.GetRowSize() == r.GetRowSize() && l.GetColumnSize() == r.GetColumnSize()) {
		IntMatrix Sum(l.GetRowSize(), l.GetColumnSize());
		for (int i = 0; i < l.GetRowSize(); i++)
			for (int j = 0; j < l.GetColumnSize(); j++) //
				Sum[i][j] = l[i][j] + r[i][j];
		return Sum;
	}
	else
		throw DimensionSumException(l.GetRowSize(), l.GetColumnSize(), r.GetRowSize(), r.GetColumnSize());
}

IntMatrix operator-(const IntMatrix& l, const IntMatrix& r) {
	if (l.GetRowSize() == r.GetRowSize() && l.GetColumnSize() == r.GetColumnSize()) {
		IntMatrix Dif(l.GetRowSize(), l.GetColumnSize());
		for (int i = 0; i < l.GetRowSize(); i++)
			for (int j = 0; j < l.GetColumnSize(); j++)
				Dif[i][j] = l[i][j] - r[i][j];
		return Dif;
	}
	else
		throw DimensionSumException(l.GetRowSize(), l.GetColumnSize(), r.GetRowSize(), r.GetColumnSize());
}

IntMatrix operator*(const IntMatrix& l, const IntMatrix& r) {
	if (l.GetColumnSize() == r.GetRowSize()) {
		IntMatrix Composit(l.GetRowSize(), r.GetColumnSize());
		for (int i = 0; i < l.GetRowSize(); i++)
			for (int j = 0; j < r.GetColumnSize(); j++)
				for (int k = 0; k < l.GetColumnSize(); k++)
					Composit[i][j] += l[i][k] * r[k][j];
		return Composit;
	}
	else
		throw DimensionComposException(l.GetColumnSize(), r.GetRowSize());
}

bool operator==(const IntMatrix& l, const IntMatrix& r)
{
	bool flag = l.GetRowSize() == r.GetRowSize() && l.GetColumnSize() == r.GetColumnSize();
	if (flag) {
		for (int i = 0; i < l.GetRowSize() && flag; i++)
			for (int j = 0; j < l.GetColumnSize() && flag; j++)
				flag = l[i][j] == r[i][j];
		return flag;
	}
	else 
		throw DimensionSumException(l.GetRowSize(), l.GetColumnSize(), r.GetRowSize(), r.GetColumnSize());
}

bool operator!=(const IntMatrix& l, const IntMatrix& r)
{
	bool flag = l.GetRowSize() != r.GetRowSize() || l.GetColumnSize() != r.GetColumnSize();
	if (!flag) {
		for (int i = 0; i < l.GetRowSize() && !flag; i++)
			for (int j = 0; j < l.GetColumnSize() && !flag; j++)
				flag = l[i][j] != r[i][j];
		return flag;
	}
	else
		throw DimensionSumException(l.GetRowSize(), l.GetColumnSize(), r.GetRowSize(), r.GetColumnSize());
}

bool operator<(const IntMatrix& l, const IntMatrix& r)
{

	double d1 = double(l);
	double d2 = double(r);
	return d1 < d2;
}

bool operator<=(const IntMatrix& l, const IntMatrix& r)
{
	double d1 = double(l);
	double d2 = double(r);
	return d1 <= d2;
}

bool operator>(const IntMatrix& l, const IntMatrix& r)
{
	double d1 = double(l);
	double d2 = double(r);
	return d1 > d2;
}

bool operator>=(const IntMatrix& l, const IntMatrix& r)
{
	double d1 = double(l);
	double d2 = double(r);
	return d1 >= d2;
}

void OutputMatrixVer1(const IntMatrix& x, const char* s, FILE* file) {
	fprintf(file, "'%s': \n", s);
	if (x.GetRowSize() != 0 && x.GetColumnSize() != 0) {
		for (int i = 0; i < x.GetRowSize(); i++) {
			for (int j = 0; j < x.GetColumnSize(); j++)
				fprintf(file, "%d\t", x.GetElement(i, j));
			fprintf(file, "\n");
		}
	}
	else
		fprintf(file, "Matrix '%s' is empty", s);
	fprintf(file, "\n");
	return;
}

void OutputMatrixVer2(const IntMatrix& x, const char* s, FILE* file) {
	if (x.GetRowSize() != 0 && x.GetColumnSize() != 0) {
		fprintf(file, "'%s': \n", s);
		for (int i = 0; i < x.GetRowSize(); i++) {
			for (int j = 0; j < x.GetColumnSize(); j++)
				fprintf(file, "%d\t", x[i][j]);
			fprintf(file, "\n");
		}
	}
	else
		throw EmptyMatrixException();
	//fprintf(file, "\n");
	return;
}

void RandomFill(IntMatrix& x, char c, FILE* file) {
	if (x.GetRowSize() != 0 && x.GetColumnSize() != 0) {
		fprintf(file, "Matrix '%c' was filled randomly\n\n", c);
		for (int i = 0; i < x.GetRowSize(); i++)
			for (int j = 0; j < x.GetColumnSize(); j++)
				x[i][j] = rand() % 20 + 1;
	}
	else
		throw EmptyMatrixException();
	return;
}
