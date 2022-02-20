#include "exception.h"

void BadDimensionException::Message() {
	printf("Uncorrect size of matrix %d x %d", m, n);
}

void DimensionSumException::Message() {
	printf("Sizes of matrixes is not equal (%d x %d) != (%d x %d)", m1, n1, m2, n2);
}

void DimensionComposException::Message() {
	printf("The number of columns in the left matrix must match the number of rows in the second matrix %d != %d", n1, m2);
}

void BadLeftIndexException::Message() {
	printf("Bad left index %d", i);
}

void BadRightIndexException::Message() {
	printf("Bad right index %d", j);
}

void EmptyMatrixException::Message() {
	printf("Empty matrix is unexeptable for this operation");
}
