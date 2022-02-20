//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "static.h"

int MatrixInput(int x[][NMAX], int& m, int& n, char* fname) {//ввод из файла
    FILE* file;                                              //если ввод был осуществлен без ошибок, 
    fopen_s(&file, fname, "r");                              //возвращается 1, в противном случае - 0
    bool flag = true;
    if (file == NULL) { //файл отсутствует
        printf("Невозможно открыть файл '%s'\n", fname);
        flag = false;
    }
    else if (fscanf_s(file, "%d%d", &m, &n) < 2) { //файл пуст
        printf("Ошибка чтения из файла '%s'\n", fname);
        flag = false;
        fclose(file);
    }
    else if (m < 1 || m > NMAX || n < 1 || n > NMAX) { //проверка диапазона
        printf("Количество строк и столбцов матрицы должны быть от 1 до %d!(файл '%s')\n", NMAX, fname);
        flag = false;
        fclose(file);
    }
    if (flag) {
        for (int i = 0; i < m && flag; i++) {
            for (int j = 0; j < n && flag; j++) {
                if (fscanf_s(file, "%d", &x[i][j]) < 1) { //проверка на "непустоту" поля
                    printf("Ошибка чтения из файла '%s'\n", fname);
                    flag = false;
                }
            }
        }
        fclose(file);
    }
    return flag;
}

int MatrixInput(int x[][NMAX], int& m, int& n, char c) { //ввод с клавиатуры
    printf("Введите количество строк и столбцов матрицы '%c': \n", c);
    scanf_s("%d", &m);
    scanf_s("%d", &n);
    bool flag = true;
    if (m < 1 || m > NMAX || n < 1 || n > NMAX) { //проверка диапазона
        printf("Количество строк и столбцов матрицы должны быть от 1 до %d!\n", NMAX);
        flag = false;
    }
    for (int i = 0; i < m && flag; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введите очередной элемент матрицы '%c': \n", c);
            scanf_s("%d", &x[i][j]);
        }
    }
    return flag;
}

//обработка матрицы целиком
int NumZerosMatrix(const int x[][NMAX], int m, int n) { //подсчёт количества нулей матрицы статическая версия
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0)
                ++result;
        }
    }
    return result;
}

void Multiplication(const int x[][NMAX], int y[], int m, int n) {
    for (int i = 0; i < m; i++) {
        int result_i = 0;
        bool first = true;
        for (int j = 0; j < n; j++) {
            if (x[i][j] != 0) {
                if (first) { //возможен случай нулевой строки
                    result_i = 1;
                    first = false;
                }
                result_i *= x[i][j];
            }
        }
        y[i] = result_i;
    }
    return;
}

//функции обработки матрицы построчно
int NumZerosOneLine(const int x[], int n) {
    int result_i = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) {
            result_i++;
        }
    }
    return result_i;
}

int NumZerosLines(const int x[][NMAX], int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        result += NumZerosOneLine(x[i], n);
    }
    return result;
}

int Multiplication(const int x[], int n) { //произведение ненулевых элементов в массиве static
    int result = 0;
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            if (first) { //возможен случай, когда вся строчка состоит из нулей
                result = 1;
                --first;
            }
            result *= x[i];
        }
    }
    return result;
}

//вывод результатов обработки целой матрицы
void OutputResultByLine(const int y[], int m, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, y[i]);
    }
    return;
}

void OutputResultByLine(const int y[], int m, char c, FILE* f) {
    fprintf(f, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(f, "В строке %d матрицы '%c' произведение ненулевых элементов\t%d\n", i + 1, c, y[i]);
    }
    return;
}

//вывод результатов обработки построчно
void OutputResultByLine(const int x[][NMAX], int m, int n, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

void OutputResultByLine(const int x[][NMAX], int m, int n, char c, FILE* file) {
    fprintf(file, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(file, "В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

//вывод матрицы
void OutputMatrix(const int x[][NMAX], int m, int n, char c) {
    printf("Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    return;
}

void OutputMatrix(const int x[][NMAX], int m, int n, char c, FILE* file) {
    fprintf(file, "Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fprintf(file, "%d\t", x[i][j]);
        fprintf(file, "\n");
    }
    return;
}

void OutputMas(int x[], int n, char c) {
    printf("Массив '%c': \n", c);
    for (int i = 0; i < n; i++)
        printf("%d\t", x[i]);
    printf("\n");
    return;
}

void OutputMas(int x[], int n, char c, FILE* f) {
    fprintf(f, "Массив '%c': \n", c);
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\t", x[i]);
    fprintf(f, "\n");
    return;
}