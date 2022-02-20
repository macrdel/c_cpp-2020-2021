#pragma once
#include <cstdio>
#define strsize 10

extern "C" __declspec(dllexport) void Run (FILE* ifile, FILE* ofile, int n); //функция должна быть доступна приложению, использующему библиотеку, 
                                                                             //и имена должны преобразовываться по правилам языка С

inline bool IsLetterOrDigitOrSpace(char c);

int StringLen(char* str, int i);

void ReadString(FILE* file, char*& str, int i, char c);

void Transfer(char*& str, int lenstr, int pos, int diff);

void Insert(char*& str, char* new_ss, int lenstr, int lenold, int lennew, int pos);

int Pos(char* str, char* ss, int& i, int j);

void InsertAll(char*& str, char* old_ss, char* new_ss, int lenold, int lennew);