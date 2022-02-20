//Определить в каком массиве больше количество элементов, больших заданного числа.
//Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.

#include "unit.h"

void main(int argc, char* argv[]) {
	double* a, * b, * c;

	int t = 0; //задающее условие число

	setlocale(LC_ALL, "rus");

	printf("Введите число:\n");
	scanf_s("%d", &t);

	int na = 0; //количество элементов в массиве A
	int nb = 0; //количество элементов в массиве B
	int nc = 0; //количество элементов в массиве C

	/*if (!InputN(na, 'A') || !InputN(nb, 'B') || !InputN(nc, 'C'))
		return;
	a = new int[na];
	b = new int[nb];
	c = new int[nc];
	ArrayInput(a, na, 'A');
	ArrayInput(b, nb, 'B');
	ArrayInput(c, nc, 'C');*/

	if (argc < 5) { //проверяем количество аргументов команды (параметров командной строки)
		printf("Недостаточно параметров!\n");
		return;
	}
	FILE* fa, * fb, * fc;
	fopen_s(&fa, argv[1], "r"); fopen_s(&fb, argv[2], "r"); fopen_s(&fc, argv[3], "r");
	if (!InputN(na, argv[1], fa) || !InputN(nb, argv[2], fb) || !InputN(nc, argv[3], fc))
		return;
	a = new double[na];
	b = new double[nb];
	c = new double[nc];
	if (!ArrayInput(a, na, argv[1], fa) || !ArrayInput(b, nb, argv[2], fb) || !ArrayInput(c, nc, argv[3], fc))
		return;
	fclose(fa); fclose(fb); fclose(fc);

	FILE* outputfile;
	fopen_s(&outputfile, argv[4], "w");
	if (outputfile != NULL) {
	OutputMasF(a, na, 'A', outputfile);
	OutputMasF(b, nb, 'B', outputfile);
	OutputMasF(c, nc, 'C', outputfile);
	
	MF f;
	int p = 0;
	printf("Введите номер функции:\n1 -> EXP\n2 -> LN\n3 -> Arctg\n");
	scanf_s("%d", &p);
	switch (p) {
	case 1: f = &Exp; break;
	case 2: f = &Ln; break;
	case 3: f = &ArcTg; break;
	default:
		printf("Unknown p num!");
		return;
	}
	
	int ka = NumT(a, na, t, f); // в каждом массиве находим количество элементов, больших t
	int kb = NumT(b, nb, t, f);
	int kc = NumT(c, nc, t, f);

	OutputMasF(a, na, 'A', outputfile);
	OutputMasF(b, nb, 'B', outputfile);
	OutputMasF(c, nc, 'C', outputfile);
	OutputResultF(t, ka, kb, kc, outputfile);
	fclose(outputfile);
	}
	else
		printf("Невозможно открыть файл '%s'\n", argv[4]);

	delete[] a;
	delete[] b;
	delete[] c;
	return;
}