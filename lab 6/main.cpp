//Написать функцию, которая возвращает величину x после 
//выполнения в ней циклического сдвига влево на n бит.
#define _CRT_SECURE_NO_WARNINGS
#include "cstdio"

unsigned CycleShift(unsigned r, size_t n) {
	return (r << n) | (r >> (32 - n));
}

void BinOutput(unsigned r, FILE* f) {
	for (int i = 31; i >= 0; i--) {
		fprintf(f, "%d", (r >> i) & 1);
	}
	fprintf(f, "\n");
	return;
}

void main(int argc, char* argv[]) {
	unsigned r = 0;
	size_t n = 0;
	FILE* inputfile = fopen(argv[1], "r");
	FILE* outputfile = fopen(argv[2], "w");

	if (inputfile != NULL && outputfile != NULL) {
	fscanf(inputfile, "%u%d", &r, &n);
	if (n > 31 || n < 0) {
		printf("Uncorrect amount of bits!");
		return;
	}
	fprintf(outputfile, "Initial number:\n%u\n", r);
	BinOutput(r, outputfile);
	r = CycleShift(r, n);
	fprintf(outputfile, "Modified number:\n%u\n", r);
	BinOutput(r, outputfile);	
	printf("OK!");
	fclose(inputfile);
	fclose(outputfile);
	}
	else
		printf("Сan't open file!");

	return;
}

//7 6 5 4 3 2 1 0 // r = 160
//1 0 1 0 0 0 0 0
//
//// n = 3
//
//7 6 5 4 3 2 1 0
//0 0 0 0 0 0 0 0 // r << n
//
//7 6 5 4 3 2 1 0
//0 0 0 0 0 1 0 1 // r >> (32 - n)
//
//// (r << n) | (r >> (32 - n))
//  0 0 0 0 0 0 0 0
//|
//  0 0 0 0 0 1 0 1
//  ---------------
//  0 0 0 0 0 1 0 1 