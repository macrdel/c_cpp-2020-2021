#define _CRT_SECURE_NO_WARNINGS
#include "unit.h"

void main() {
	FILE* inputfile = fopen("input.txt", "r");
	FILE* outputfile = fopen("output.txt", "w");
	if (inputfile != NULL && outputfile != NULL) {
		fseek(inputfile, 0, SEEK_END);
		int n = ftell(inputfile);
		rewind(inputfile);

		//Статическая
		Run(inputfile, outputfile, n);

		//Динамическая
		//HINSTANCE hLib = LoadLibrary(TEXT("Make_Dll_Eighth_Lab.dll")); //oбъявляем идентификатор библиотеки и загружаем её
		//if (hLib == NULL)                                              //проверяем результат загрузки библиотеки
		//	printf("Unable to load the library 'Make_Dll_Eighth_Lab.dll'!\n");
		//else {
		//	LibFunc R = (LibFunc)GetProcAddress(hLib, "Run");          //получаем указатель на функцию Run и преобразуем его к нужному типу
		//	if (!R)                                                    //проверяем полученный параметр
		//		printf("Unable to find the function 'Run'!\n\n");
		//	else
		//		R(inputfile, outputfile, n);
		//	FreeLibrary(hLib);                                         //освобождаем библиотеку
		//}

		fclose(inputfile);
		fclose(outputfile);
	}
	else
		printf("File not exist!\n");
	return;
}