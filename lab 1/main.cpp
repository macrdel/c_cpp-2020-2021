//Определить в каком массиве больше количество элементов, больших заданного числа.
//Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.

#include "unit.h"

void main(int argc, char* argv[]) {
	int a[nmax], b[nmax], c[nmax];

	int t = 0; //задающее условие число
	
	setlocale(LC_ALL, "rus");
	
	printf("Введите число:\n");
	scanf_s("%d", &t);

	int na = 0; //количество элементов в массиве A
	int nb = 0; //количество элементов в массиве B
	int nc = 0; //количество элементов в массиве C

	//if (!ArrayInput(a, na, 'A') || !ArrayInput(b, nb, 'B') || !ArrayInput(c, nc, 'C')) 
	//  return;

	if (argc < 5) { //проверяем количество аргументов команды (параметров командной строки)
	  printf("Недостаточно параметров!\n");
	  return;
	}
	if (!ArrayInput(a, na, argv[1]) || !ArrayInput(b, nb, argv[2]) || !ArrayInput(c, nc, argv[3])) 
		return;
	

	int ka = NumT(a, na, t); // в каждом массиве находим количество элементов, больших t
	int kb = NumT(b, nb, t);
	int kc = NumT(c, nc, t);

	//OutputMas(a, na, 'A');
	//OutputMas(b, nb, 'B');
	//OutputMas(c, nc, 'C');
	//OutputResult(t, ka, kb, kc);

	FILE* outputfile;
	fopen_s(&outputfile, argv[4], "w");
	if (outputfile != NULL) {
		OutputMasF(a, na, 'A', outputfile);
		OutputMasF(b, nb, 'B', outputfile);
		OutputMasF(c, nc, 'C', outputfile);
		OutputResultF(t, ka, kb, kc, outputfile);
		fclose(outputfile);
	}
	else {
		printf("Невозможно открыть файл '%s'\n", argv[4]);
	}
}