// dllmain.cpp : Определяет точку входа для приложения DLL.
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "unit.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

inline bool IsLetterOrDigitOrSpace(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ') || (c >= '0' && c <= '9');
}

int StringLen(char* str, int i) {
	return (str[i]) ? StringLen(str, ++i) : i;
}

void ReadString(FILE* file, char*& str, int i, char c) {
	if (!feof(file) && c != '\n') {
		if (c != 0 && IsLetterOrDigitOrSpace(c))
			str[i++] = c;
		fscanf_s(file, "%c", &c);
		return ReadString(file, str, i, c);
	}
	str[i] = '\0';
	return;
}

void Transfer(char*& str, int lenstr, int pos, int diff) { //сдвиг массива, начиная с позиции pos; влево(начиная с pos), если
	for (int i = pos, j = lenstr; i <= lenstr || j >= pos; i++, j--) // новая подстрока меньше старой
		(diff < 0) ? (str[i + diff] = str[i]) : (str[j + diff] = str[j]); //вправо(начиная с конца), если новая больше старой
	return;
}

void Insert(char*& str, char* new_ss, int lenstr, int lenold, int lennew, int pos) {
	if (lenold != lennew) //сдвиг не всегда необходим
		Transfer(str, lenstr, pos, lennew - lenold);
	for (int i = pos - lenold, j = 0; new_ss[j]; i++, j++) //вписываем новую подстроку
		str[i] = new_ss[j];
	return;
}

int Pos(char* str, char* ss, int& i, int j) {
	return (!str[i] && ss[j]) ? -1 : ((ss[j]) ? ((str[i] == ss[j]) ? Pos(str, ss, ++i, ++j) : Pos(str, ss, ++i, 0)) : i);
}

void InsertAll(char*& str, char* old_ss, char* new_ss, int lenold, int lennew) {
	int i = 0;
	while ((i = Pos(str, old_ss, i, 0)) != -1)
		Insert(str, new_ss, StringLen(str, 0), lenold, lennew, i); //поскольку длина исходной может меняться,
	return;                                                        //подсчитываем её каждый раз заново
}

extern "C" __declspec(dllexport) void Run(FILE * ifile, FILE * ofile, int n) {
	char* source = new char[n];
	char* old_ss = new char[strsize];
	char* new_ss = new char[strsize];
	ReadString(ifile, source, 0, 0);
	ReadString(ifile, old_ss, 0, 0);
	ReadString(ifile, new_ss, 0, 0);
	fprintf(ofile, "Source string: %s\nOld substring: %s\nNew substring: %s\n", source, old_ss, new_ss);
	InsertAll(source, old_ss, new_ss, StringLen(old_ss, 0), StringLen(new_ss, 0));
	fprintf(ofile, "New source string: %s", source);
	//fclose(ifile); fclose(ofile);
	delete[] source;
	delete[] old_ss;
	delete[] new_ss;
	return;
}