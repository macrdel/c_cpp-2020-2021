#include "header.h"

void InputTextToBin(const char* tname, const char* bname) {
	FILE* tfile;
	FILE* bfile;
	fopen_s(&tfile, tname, "r");
	fopen_s(&bfile, bname, "wb");
	if (tfile == NULL) {
		 ERROR = 2; //невозможно открыть входной текстовый
	}
	else if (bfile == NULL) {
		ERROR = 3; //невозможно открыть бинарный для записи
	}

	if (!ERROR) {
		Record buf;
		bool flag = false; //если недостаточно данных
		while (!feof(tfile)) {
			int i = 0;
			while (i < N && !feof(tfile)) {
				if (fscanf_s(tfile, "%f", &buf[i])) { //считываем только элементы типа float
					i++;
				}
				if (fgetc(tfile) == '\n') { //дойдя до конца строки, переходим на новую
					fscanf_s(tfile, "\n");
				}
			}
			if (i == N) { //в бинарный записываем только структуры без вакантных мест
				fwrite(buf, sizeof(Record), 1, bfile);
				flag = true;
			}
		}
		if (!flag) {
			ERROR = 4;
		}
		fclose(tfile);
		fclose(bfile);
	}
	return;
}

void OutputBinToText(const char* bname, const char* tname, const char* message) {
	FILE* bfile;
	FILE* tfile;
	fopen_s(&bfile, bname, "rb+");
	fopen_s(&tfile, tname, "a+");
	if (bfile == NULL) {
		ERROR = 5; //невозможно открыть бинарный файл для считывания
	}
	else if (tfile == NULL) {
		ERROR = 6; //невозможно открыть выходной текстовый
	}

	if (!ERROR) {
		fprintf(tfile, "Содержимое бинарного файла %s\n", message);
		Record buf;
		int k = 0;
		while (fread(buf, sizeof(Record), 1, bfile) == 1) {
			fprintf(tfile, "Запись %d --> %c", ++k, '[');
			for (int i = 0; i < N - 1; i++)
				fprintf(tfile, "%f%c  ", buf[i], ';');
			fprintf(tfile, "%f%c%c", buf[N - 1], ']', '\n');
		}
		fprintf(tfile, "\n");
		fclose(bfile);
		fclose(tfile);
	}
	return;
}

void Replacement(const char* bname) {
	FILE* bfile;
	fopen_s(&bfile, bname, "r+b");
	if (bfile == NULL) {
		ERROR = 7; // невозможно открыть бинарный файл для изменения
	}
	if (!ERROR) {
		int t1, t2;
		fseek(bfile, 0, SEEK_END); // нахождение размера файла в Record
		int s = ftell(bfile) / (sizeof(Record));
		printf("Общее количество записей в бинарном файле %d\n", s);
		if (s == 1) {
			printf("Всего одна запись!\n");
		} 
		else {
			printf("Введите номера двух записей, которые Вы хотите поменять местами\n");
			scanf_s("%d%d", &t1, &t2);
			if (t1 > s || t2 > s) {
				ERROR = 8; // номера записей, которые надо поменять местами, выходят за пределы общего количества записей 
			}
		}

		if (!ERROR && s != 1) {
			if (t1 > t2) { //t1 < t2 всегда
				int x = t1;
				t1 = t2;
				t2 = x;
			}

			Record buf_t1, buf_t2;
			fseek(bfile, (t2 - 1) * sizeof(Record), SEEK_SET);
			fread(buf_t2, sizeof(Record), 1, bfile); // считаем запись с большим номером

			fseek(bfile, (t1 - 1) * sizeof(Record), SEEK_SET);
			fread(buf_t1, sizeof(Record), 1, bfile); // считаем запись с меньшим номером

			fseek(bfile, (t1 - 1) * sizeof(Record), SEEK_SET);
			fwrite(buf_t2, sizeof(Record), 1, bfile); // запись с большим номером в меньший номер

			fseek(bfile, (t2 - 1) * sizeof(Record), SEEK_SET);
			fwrite(buf_t1, sizeof(Record), 1, bfile); // запись с меньшим номером в больший номер
		}

		fclose(bfile);
	}
	return;
}