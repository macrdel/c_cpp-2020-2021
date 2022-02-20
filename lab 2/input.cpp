//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "unit.h"

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

void MatrixInput(int** x, int m, int n, char c) { //с клавиатуры (тоже для динамического)
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            printf("Введите элемент матрицы '%c': \n", c);
            scanf_s("%d", &x[i][j]);
        }
    return;
}

int MatrixInput(int** x, int m, int n, char* fname, FILE* file) { //из файла (тоже для динамического)
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