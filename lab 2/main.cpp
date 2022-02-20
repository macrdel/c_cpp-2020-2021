//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "dynamic.h"
#include "static.h"

void main(int argc, char* argv[]) {
	int n1 = 0; 
	int n2 = 0; 
	int n3 = 0;
	
	setlocale(LC_ALL, "ru");

	printf("Choose a processing method\n");
	printf("1 - Matrix\n2 - Line\n");
	scanf_s("%d", &n1);
	printf("\n");
	printf("Choose a storage method\n");
	printf("1 - Static\n2 - Dynamic\n");
	scanf_s("%d", &n2);
	printf("\n");
	printf("Choose an input method\n");
	printf("1 - Console\n2 - File\n");
	scanf_s("%d", &n3);
	printf("\n");

	int ma = 0; int na = 0;
	int mb = 0; int nb = 0;
	int a_s[NMAX][NMAX], b_s[NMAX][NMAX];
	int** a_d, ** b_d;
	int ka = 0; int kb = 0;

	switch (n1) {
	case 1:
		switch (n2) {
		case 1 :
			switch (n3) {
			case 1: //матричная обработка, статический массив, вв консоль
				if (!MatrixInput(a_s, ma, na, 'A') || !MatrixInput(b_s, mb, nb, 'B'))
						break;

				ka = NumZerosMatrix(a_s, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosMatrix(b_s, mb, nb);

				OutputMatrix(a_s, ma, na, 'A');
				OutputMatrix(b_s, mb, nb, 'B');

				printf("В матрице 'A' количество нулевых элементов\t%d\n", ka);
				printf("В матрице 'B' количество нулевых элементов\t%d\n", kb);

				int y[NMAX]; //массив произведений ненулевых элементов каждой строки нужной матрицы
				if (ka < kb) {
					Multiplication(a_s, y, ma, na);
					OutputResultByLine(y, ma, 'A');
					OutputMas(y, ma, 'Y');
				}
				else if (kb < ka) {
					Multiplication(b_s, y, mb, nb);
					OutputResultByLine(y, mb, 'B');
					OutputMas(y, mb, 'Y');
				}
				else {
					printf("Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
				}

				break;
			case 2: //матричная обработка, статический массив, вв файл
				if (argc < 4) { //проверяем количество аргументов команды (параметров командной строки)
					printf("Недостаточно параметров!\n");
					break;
				}
				if (!MatrixInput(a_s, ma, na, argv[1]) || !MatrixInput(b_s, mb, nb, argv[2]))
					break;

				ka = NumZerosMatrix(a_s, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosMatrix(b_s, mb, nb);

				FILE* outputfile;
				fopen_s(&outputfile, argv[3], "w");
				if (outputfile != NULL) {
					OutputMatrix(a_s, ma, na, 'A', outputfile);
					OutputMatrix(b_s, mb, nb, 'B', outputfile);
					fprintf(outputfile, "В матрице 'A' количество нулевых элементов\t%d\n", ka);
					fprintf(outputfile, "В матрице 'B' количество нулевых элементов\t%d\n", kb);
					int y[NMAX]; //массив произведений ненулевых элементов каждой строки нужной матрицы
					if (ka < kb) {
						Multiplication(a_s, y, ma, na);
						OutputResultByLine(y, ma, 'A', outputfile);
						OutputMas(y, ma, 'Y', outputfile);
					}
					else if (kb < ka) {
						Multiplication(b_s, y, mb, nb);
						OutputResultByLine(y, mb, 'B', outputfile);
						OutputMas(y, mb, 'Y', outputfile);
					}
					else {
						fprintf(outputfile, "Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
					}
					fclose(outputfile);
				}
				else {
					printf("Невозможно открыть файл '%s'\n", argv[3]);
				}

				break;
			default:
				printf("Unknown command!");
			}
			break;
		case 2 :
			switch (n3) {
			case 1: //матричная обработка, динамический массив, вв консоль
				if (!InputMN(ma, na, 'A') || !InputMN(mb, nb, 'B'))
					break;
				a_d = AllocMatrix(ma, na);
				b_d = AllocMatrix(mb, nb);
				MatrixInput(a_d, ma, na, 'A');
				MatrixInput(b_d, mb, nb, 'B');

				ka = NumZerosMatrix(a_d, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosMatrix(b_d, mb, nb);

				OutputMatrix(a_d, ma, na, 'A');
				OutputMatrix(b_d, mb, nb, 'B');

				printf("В матрице 'A' количество нулевых элементов\t%d\n", ka);
				printf("В матрице 'B' количество нулевых элементов\t%d\n", kb);

				if (ka < kb) {
					int* y = new int[ma];
					Multiplication(a_d, y, ma, na);
					OutputResultByLine(y, ma, 'A');
					OutputMas(y, ma, 'Y');
					delete[] y;
				}
				else if (kb < ka) {
					int* y = new int[mb];
					Multiplication(b_d, y, mb, nb);
					OutputResultByLine(y, mb, 'B');
					OutputMas(y, mb, 'Y');
					delete[] y;
				}
				else {
					printf("Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
				}
				FreeMatrix(a_d, ma);
				FreeMatrix(b_d, mb);
				break;
			case 2: //матричная обработка, динамический массив, вв файл
				if (argc < 4) {
					printf("Недостаточно параметров!\n");
					break;
				}
				FILE* fa, * fb;
				fopen_s(&fa, argv[1], "r"); fopen_s(&fb, argv[2], "r");
				if (!InputMN(ma, na, argv[1], fa) || !InputMN(mb, nb, argv[2], fb))
					break;
				a_d = AllocMatrix(ma, na);
				b_d = AllocMatrix(mb, nb);
				if (!MatrixInput(a_d, ma, na, argv[1], fa) || !MatrixInput(b_d, mb, nb, argv[2], fb))
					break;
				fclose(fa); fclose(fb);

				ka = NumZerosMatrix(a_d, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosMatrix(b_d, mb, nb);

				FILE* outputfile;
				fopen_s(&outputfile, argv[3], "w");
				if (outputfile != NULL) {
					OutputMatrix(a_d, ma, na, 'A', outputfile);
					OutputMatrix(b_d, mb, nb, 'B', outputfile);
					fprintf(outputfile, "В матрице 'A' количество нулевых элементов\t%d\n", ka);
					fprintf(outputfile, "В матрице 'B' количество нулевых элементов\t%d\n", kb);
					if (ka < kb) {
						int* y = new int[ma];
						Multiplication(a_d, y, ma, na);
						OutputResultByLine(y, ma, 'A', outputfile);
						OutputMas(y, ma, 'Y', outputfile);
						delete[] y;
					}
					else if (kb < ka) {
						int* y = new int[mb];
						Multiplication(b_d, y, mb, nb);
						OutputResultByLine(y, mb, 'B', outputfile);
						OutputMas(y, mb, 'Y', outputfile);
						delete[] y;
					}
					else {
						fprintf(outputfile, "Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
					}
					fclose(outputfile);
				}
				else {
					printf("Невозможно открыть файл '%s'\n", argv[3]);
				}
				FreeMatrix(a_d, ma);
				FreeMatrix(b_d, mb);
				break;
			default:
				printf("Unknown command!");
			}
			break;
		default:
			printf("Unknown command!");
		}
		break;
	case 2:
		switch (n2) {
		case 1:
			switch (n3) {
			case 1: //построчная обработка, статический массив, вв консоль
				if (!MatrixInput(a_s, ma, na, 'A') || !MatrixInput(b_s, mb, nb, 'B'))
					break;

				ka = NumZerosLines(a_s, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosLines(b_s, mb, nb);

				OutputMatrix(a_s, ma, na, 'A');
				OutputMatrix(b_s, mb, nb, 'B');

				printf("В матрице 'A' количество нулевых элементов\t%d\n", ka);
				printf("В матрице 'B' количество нулевых элементов\t%d\n", kb);

				if (ka < kb) {
					OutputResultByLine(a_s, ma, na, 'A');
				}
				else if (kb < ka) {
					OutputResultByLine(b_s, mb, nb, 'B');
				}
				else {
					printf("Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
				}

				break;
			case 2: //построчная обработка, статический массив, вв файл
				if (argc < 4) { //проверяем количество аргументов команды (параметров командной строки)
					printf("Недостаточно параметров!\n");
					break;
				}
				if (!MatrixInput(a_s, ma, na, argv[1]) || !MatrixInput(b_s, mb, nb, argv[2]))
					break;

				ka = NumZerosLines(a_s, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosLines(b_s, mb, nb);

				FILE* outputfile;
				fopen_s(&outputfile, argv[3], "w");
				if (outputfile != NULL) {
					OutputMatrix(a_s, ma, na, 'A', outputfile);
					OutputMatrix(b_s, mb, nb, 'B', outputfile);
					fprintf(outputfile, "В матрице 'A' количество нулевых элементов\t%d\n", ka);
					fprintf(outputfile, "В матрице 'B' количество нулевых элементов\t%d\n", kb);
					if (ka < kb) {
						OutputResultByLine(a_s, ma, na, 'A', outputfile);
					}
					else if (kb < ka) {
						OutputResultByLine(b_s, mb, nb, 'B', outputfile);
					}
					else {
						fprintf(outputfile, "Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
					}
					fclose(outputfile);
				}
				else {
					printf("Невозможно открыть файл '%s'\n", argv[3]);
				}

				break;
			default:
				printf("Unknown command!");
			}
			break;
		case 2:
			switch (n3) {
			case 1: //построчная обработка, динамический массив, вв консоль
				if (!InputMN(ma, na, 'A') || !InputMN(mb, nb, 'B'))
					break;
				a_d = AllocMatrix(ma, na);
				b_d = AllocMatrix(mb, nb);
				MatrixInput(a_d, ma, na, 'A');
				MatrixInput(b_d, mb, nb, 'B');

				ka = NumZerosLines(a_d, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosLines(b_d, mb, nb);

				OutputMatrix(a_d, ma, na, 'A');
				OutputMatrix(b_d, mb, nb, 'B');

				printf("В матрице 'A' количество нулевых элементов\t%d\n", ka);
				printf("В матрице 'B' количество нулевых элементов\t%d\n", kb);

				if (ka < kb) {
					OutputResultByLine(a_d, ma, na, 'A');
				}
				else if (kb < ka) {
					OutputResultByLine(b_d, mb, nb, 'B');
				}
				else {
					printf("Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
				}
				FreeMatrix(a_d, ma);
				FreeMatrix(b_d, mb);

				break;
			case 2: //построчная обработка, динамический массив, вв файл
				if (argc < 4) {
					printf("Недостаточно параметров!\n");
					break;
				}
				FILE* fa, * fb;
				fopen_s(&fa, argv[1], "r"); fopen_s(&fb, argv[2], "r");
				if (!InputMN(ma, na, argv[1], fa) || !InputMN(mb, nb, argv[2], fb))
					break;
				a_d = AllocMatrix(ma, na);
				b_d = AllocMatrix(mb, nb);
				if (!MatrixInput(a_d, ma, na, argv[1], fa) || !MatrixInput(b_d, mb, nb, argv[2], fb))
					break;
				fclose(fa); fclose(fb);

				ka = NumZerosLines(a_d, ma, na); //подсчитываем количество нулей каждой матрицы
				kb = NumZerosLines(b_d, mb, nb);

				FILE* outputfile;
				fopen_s(&outputfile, argv[3], "w");
				if (outputfile != NULL) {
					OutputMatrix(a_d, ma, na, 'A', outputfile);
					OutputMatrix(b_d, mb, nb, 'B', outputfile);
					fprintf(outputfile, "В матрице 'A' количество нулевых элементов\t%d\n", ka);
					fprintf(outputfile, "В матрице 'B' количество нулевых элементов\t%d\n", kb);
					if (ka < kb) {
						OutputResultByLine(a_d, ma, na, 'A', outputfile);
					}
					else if (kb < ka) {
						OutputResultByLine(b_d, mb, nb, 'B', outputfile);
					}
					else {
						fprintf(outputfile, "Количество нулевых элементов в обеих матрицах матрицах одинаково\n");
					}
					fclose(outputfile);
				}
				else {
					printf("Невозможно открыть файл '%s'\n", argv[3]);
				}
				FreeMatrix(a_d, ma);
				FreeMatrix(b_d, mb);
				break;
			default:
				printf("Unknown command!");
			}
			break;
		default:
			printf("Unknown command!");
		}
		break;
	default:
		printf("Unknown command!");
	}

	return;

}