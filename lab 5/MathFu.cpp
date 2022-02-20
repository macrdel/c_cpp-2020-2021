#include "MathFu.h"

double Exp(double q) {
	return exp(q);
}

double Ln(double q) {
	return (q != 0) ? log(abs(q)) : 0;
}

double ArcTg(double q) {
	return atan(q);
}