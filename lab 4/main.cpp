//сформировать строку заменой в исходной строке заданной подстроки на другую заданную подстроку(возможно разной длины)
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define strsize 10

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
		fscanf(file, "%c", &c);
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
	if (!str[i] && ss[j]) //прерываем рекурсию, если достигнут конец source-строки
		return -1;
	if (ss[j]) //прерываем рекурсию, если мы нашли первое вхождение old_ss в source
		return (str[i] == ss[j]) ? Pos(str, ss, ++i, ++j) : Pos(str, ss, ++i, 0);
	return i;
}

//int Pos(char* str, char* ss, int i, int j) {
//	return (!str[i] && ss[j]) ? -1 : ((ss[j]) ? ((str[i] == ss[j]) ? Pos(str, ss, ++i, ++j) : Pos(str, ss, ++i, 0)) : i);
//}

void InsertAll(char*& str, char* old_ss, char* new_ss, int lenold, int lennew) {
	int i = 0;
	while ((i = Pos(str, old_ss, i, 0)) != -1)
		Insert(str, new_ss, StringLen(str, 0), lenold, lennew, i); //поскольку длина исходной может меняться,
	return;                                                        //подсчитываем её каждый раз заново
}

void main(int argc, char* argv[]) {
	FILE* inputfile; FILE* outputfile;
	if ((inputfile = fopen("input.txt", "r")) == NULL || (outputfile = fopen("output.txt", "w")) == NULL)
		return;
	fseek(inputfile, 0, SEEK_END);
	int n = ftell(inputfile);
	rewind(inputfile);
	char* source = new char[n];
	char* old_ss = new char[strsize];
	char* new_ss = new char[strsize];
	ReadString(inputfile, source, 0, 0);
	ReadString(inputfile, old_ss, 0, 0);
	ReadString(inputfile, new_ss, 0, 0);
	fprintf(outputfile, "Source string: %s\nOld substring: %s\nNew substring: %s\n", source, old_ss, new_ss);
	InsertAll(source, old_ss, new_ss, StringLen(old_ss, 0), StringLen(new_ss, 0));
	fprintf(outputfile, "New source string: %s", source);
	fclose(inputfile); fclose(outputfile);
	delete[] source;
	delete[] old_ss;
	delete[] new_ss;
	return;
}
