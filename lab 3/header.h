#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int N = 4;

typedef float Record[N];

extern int ERROR;

void InputTextToBin(FILE* tfile, FILE* bfile);

void OutputBinToText(FILE* bfile, FILE* tfile, const char* message);

void Replacement(FILE* bfile);