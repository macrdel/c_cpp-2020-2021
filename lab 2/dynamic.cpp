//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "dynamic.h"

int** AllocMatrix(int m, int n) { //динамическая инициализация двумерного массива
    int** x = new int* [m];
    for (int i = 0; i < m; i++)
        x[i] = new int[n];
    return x;
}

void FreeMatrix(int**& x, int m) { //освобождение динамической памяти из-под двумерного массива
    for (int i = 0; i < m; i++)
        delete[] x[i];
    delete[] x;
    return;
}

int InputMN(int& m, int& n, char c) { //вводим количество строк и столбцов из консоли и проверяем диапазон (для динамического)
    bool flag = true;
    printf("Введите количество строк и столбцов матрицы '%c': \n", c);
    scanf_s("%d", &m);
    scanf_s("%d", &n);
    if (m < 1 || m > NMAX || n < 1 || n > NMAX) { //проверка диапазона
        printf("Количество строк и столбцов матрицы должны быть от 1 до %d!\n", NMAX);
        flag = false;
    }
    return flag;
}

int InputMN(int& m, int& n, char* fname, FILE* file) { //ввод количество строк и столбцов из файла (для динамического)
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
    return flag;
}

void MatrixInput(int**& x, int m, int n, char c) { //с клавиатуры (тоже для динамического)
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("Введите элемент матрицы '%c': \n", c);
            scanf_s("%d", &x[i][j]);
        }
    return;
}

int MatrixInput(int**& x, int m, int n, char* fname, FILE* file) { //из файла (тоже для динамического)
    bool flag = true;
    for (int i = 0; i < m && flag; i++)
        for (int j = 0; j < n && flag; j++)
            if (fscanf_s(file, "%d", &x[i][j]) < 1) {
                printf("Ошибка чтения из файла '%s'\n", fname);
                flag = false;
                FreeMatrix(x, m);
                fclose(file);
            }
    return flag;
}

//обработка матрицы целиком
int NumZerosMatrix(int** x, int m, int n) { //подсчёт количества нулей матрицы динамическая версия
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0)
                result++;
        }
    }
    return result;
}

void Multiplication(int** x, int*& y, int m, int n) {
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
int NumZerosOneLine(int* x, int n) {
    int result_i = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 0) {
            result_i++;
        }
    }
    return result_i;
}

int NumZerosLines(int** x, int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        result += NumZerosOneLine(x[i], n);
    }
    return result;
}

int Multiplication(int* x, int n) { //произведение ненулевых элементов в массиве dyn
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
void OutputResultByLine(int* y, int m, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, y[i]);
    }
    return;
}

void OutputResultByLine(int* y, int m, char c, FILE* f) {
    fprintf(f, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(f, "В строке %d матрицы '%c' произведение ненулевых элементов\t%d\n", i + 1, c, y[i]);
    }
    return;
}

//вывод результатов обработки построчно
void OutputResultByLine(int** x, int m, int n, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

void OutputResultByLine(int** x, int m, int n, char c, FILE* file) {
    fprintf(file, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(file, "В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

//вывод матрицы
void OutputMatrix(int** x, int m, int n, char c) {
    printf("Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    return;
}

void OutputMatrix(int** x, int m, int n, char c, FILE* file) {
    fprintf(file, "Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fprintf(file, "%d\t", x[i][j]);
        fprintf(file, "\n");
    }
    return;
}

void OutputMas(int* x, int n, char c) {
    printf("Массив '%c': \n", c);
    for (int i = 0; i < n; i++)
        printf("%d\t", x[i]);
    printf("\n");
    return;
}

void OutputMas(int* x, int n, char c, FILE* f) {
    fprintf(f, "Массив '%c': \n", c);
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\t", x[i]);
    fprintf(f, "\n");
    return;
}