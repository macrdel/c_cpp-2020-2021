//Даны две матрицы разного размера. Для той из матриц, в которой меньше количество 
//нулевых элементов, найти произведение ненулевых элементов в каждой строке.
#include "unit.h"

//вывлод результатов обработки целой матрицы
void OutputResultByLine(int const y[], int m, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, y[i]);
    }
    return;
}

void OutputResultByLine(int const y[], int m, char c, FILE* f) {
    fprintf(f, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(f, "В строке %d матрицы '%c' произведение ненулевых элементов\t%d\n", i + 1, c, y[i]);
    }
    return;
}

void OutputResultByLine(int const* y, int m, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, y[i]);
    }
    return;
}

void OutputResultByLine(int const* y, int m, char c, FILE* f) {
    fprintf(f, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(f, "В строке %d матрицы '%c' произведение ненулевых элементов\t%d\n", i + 1, c, y[i]);
    }
    return;
}

//вывод результатов обработки построчно
void OutputResultByLine(int const x[][NMAX], int m, int n, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

void OutputResultByLine(int const x[][NMAX], int m, int n, char c, FILE* file) {
    fprintf(file, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(file, "В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

void OutputResultByLine(int const** x, int m, int n, char c) {
    printf("В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        printf("В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

void OutputResultByLine(int const** x, int m, int n, char c, FILE* file) {
    fprintf(file, "В матрице '%c' количество нулевых элементов меньше\n", c);
    for (int i = 0; i < m; i++) {
        fprintf(file, "В строке %d матрицы '%c' произведение ненулевых элементов \t%d\n", i + 1, c, Multiplication(x[i], n));
    }
    return;
}

//вывод матрицы
void OutputMatrix(int const x[][NMAX], int m, int n, char c) {
    printf("Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    return;
}

void OutputMatrix(int const x[][NMAX], int m, int n, char c, FILE* file) {
    fprintf(file, "Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fprintf(file, "%d\t", x[i][j]);
        fprintf(file, "\n");
    }
    return;
}

void OutputMatrix(int const** x, int m, int n, char c) {
    printf("Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    return;
}

void OutputMatrix(int const** x, int m, int n, char c, FILE* file) {
    fprintf(file, "Матрица '%c': \n", c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fprintf(file, "%d\t", x[i][j]);
        fprintf(file, "\n");
    }
    return;
}