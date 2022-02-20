//Определить в каком массиве больше количество элементов, больших заданного числа.
//Если в двух или трёх массивах количества искомых элементов совпадают, вывести соответствующее сообщение.

#include "unit.h"

int NumT(const int x[], int n, int t) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > t) {
			k++;
		}
	}
	return k;
}

int ArrayInput(int x[], int& n, char* fname) {//ввод из файла
	FILE* file;                               //если ввод был осуществлен без ошибок, 
	fopen_s(&file, fname, "r");               //возвращается 1, в противном случае - 0
	bool flag = true;
	if (file == NULL) { //файл отсутствует
		printf("Невозможно открыть файл '%s'\n", fname);
		flag = false;
	}
	else if (fscanf_s(file, "%d", &n) < 1) { //файл пуст
		printf("Ошибка чтения из файла '%s'\n", fname);
		flag = false;
		fclose(file);
	}
	else if (n < 1 || n > nmax) { //проверка диапазона
		printf("Кол-во эл-тов массива должно быть от 1 до %d!(файл '%s')\n", nmax, fname);
		flag = false;
		fclose(file);
	}
	if (flag) {
		for (int i = 0; i < n && flag; i++) {
			if (fscanf_s(file, "%d", &x[i]) < 1) { //проверка на "непустоту" поля
				printf("Ошибка чтения из файла '%s'\n", fname);
				flag = false;
			}
		}
		fclose(file);
	}
	return flag;
}

int ArrayInput(int x[], int& n, char c) {//ввод с клавиатуры
	printf("Введите количество элементов мссива '%c': \n", c);
	scanf_s("%d", &n);
	bool flag = true;
	if (n < 1 || n > nmax) { //проверка диапазона
		printf("Кол-во эл-тов массива должно быть от 1 до %d!\n", nmax);
		flag = false;
	}
	for (int i = 0; i < n && flag; i++) {
		printf("Введите элемент массива '%c': \n", c);
		scanf_s("%d", &x[i]);
	}
	return flag;
}

void OutputResult(int t, int ka, int kb, int kc) {
	printf("Заданное число:\t%d\n", t);
	bool flag = true;
	
 if (ka == kb && kb == kc) {
	 if (ka == 0) {
		 printf("В массивах нет элементов, больших заданного числа\n");
	 }
	 else {
		 printf("Все три массива имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
	 }
		flag = false;
	}
	else if (ka == kb) {
		printf("Массивы A и B имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
	}
	else if (ka == kc) {
		printf("Массивы A и C имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
	}
	else if (kb == kc) {
		printf("Массивы B и С имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", kb);
	}
	if (flag) {
		int max = ka; //ищем максимум между ka, kb и kc
		if (kb > max) { max = kb; }
		if (kc > max) { max = kc; }
		if (ka == max) {
			printf( "В массиве A наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
		}
		if (kb == max) {
			printf("В массиве B наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
		}
		if (kc == max) {
			printf("В массиве C наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
		}
	}
	return;
}

void OutputResultF(int t, int ka, int kb, int kc, FILE* f) {
	    fprintf(f, "Заданное число:\t%d\n", t);
		bool flag = true;
		if (ka == kb && kb == kc) {
			if (ka == 0) {
				fprintf(f, "В массивах нет элементов, больших заданного числа\n");
			}
			else {
				fprintf(f, "Все три массива имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
			}
			flag = false;
		}
		else if (ka == kb) {
			fprintf(f, "Массивы A и B имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
		}
		else if (ka == kc) {
			fprintf(f, "Массивы A и C имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", ka);
		}
		else if (kb == kc) {
			fprintf(f, "Массивы B и С имеют одинаковое количество элементов, больших заданного числа, а именно: %d\n", kb);
		}
		if (flag) {
			int max = ka; //ищем максимум между ka, kb и kc
			if (kb > max) { max = kb; }
			if (kc > max) { max = kc; }
			if (ka == max) {
				fprintf(f, "В массиве A наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
			}
			if (kb == max) {
				fprintf(f, "В массиве B наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
			}
			if (kc == max) {
				fprintf(f, "В массиве C наибольшее количество элементов, больших заданного числа, а именно: %d\n", max);
			}
		}
		return;
}

void OutputMas(const int x[], int n, char c) {
	printf("Массив '%c': \n", c);
	for (int i = 0; i < n; i++)
		printf("%d\t", x[i]);
	printf("\n");
	return;
}

void OutputMasF(const int x[], int n, char c, FILE* f) {
	fprintf(f, "Массив '%c': \n", c);
	for (int i = 0; i < n; i++)
		fprintf(f, "%d\t", x[i]);	
	fprintf(f, "\n");	
	return;
}