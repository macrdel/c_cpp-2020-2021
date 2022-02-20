#include "header.h"

int ERROR = 0;

void main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	
	if (argc < 4) {
		ERROR = 1;
	}

	if (!ERROR) {
		InputTextToBin(argv[1], argv[2]);
	}
	if (!ERROR) {
		OutputBinToText(argv[2], argv[3], "до изменения");
	}
	if (!ERROR) {
		Replacement(argv[2]);
	}
	if (!ERROR) {
		OutputBinToText(argv[2], argv[3], "после изменения");
	}

	switch (ERROR)
	{
	case 0: printf("OK!\n"); break;
	case 1: printf("Недостаточно параметров!\n"); break;
	case 2: printf("Невозможно открыть входной текстовый\n"); break;
	case 3: printf("Невозможно открыть бинарный для записи\n"); break;
	case 4: printf("Недостаточно данных!\n"); break;
	case 5: printf("Невозможно открыть бинарный для считывания\n"); break;
	case 6: printf("Невозможно открыть выходной текстовый\n"); break;
	case 7: printf("Невозможно открыть бинарный файл для изменения\n"); break;
	case 8: printf("Номера записей, которые Вы хотите поменять местами, выходят за пределы общего количества\n"); break;
	}

	return;
}