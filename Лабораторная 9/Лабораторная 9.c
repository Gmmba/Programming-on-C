#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double** allocateMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(double** matrix, int rows, int cols) {
    printf("Введите элементы матрицы (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(double** matrix, int rows, int cols) {
    printf("Матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void adjustRows(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        double sumPositives = 0.0;
        int countPositives = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                sumPositives += matrix[i][j];
                countPositives++;
            }
        }
        if (countPositives > 0) {
            double average = sumPositives / countPositives;
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += average;
            }
        }
    }
}

double sumMatrix(double** matrix, int rows, int cols) {
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

double* extractAboveDiagonals(double** matrix, int rows, int cols, int* resultSize) {
    *resultSize = 0;
    int maxSize = rows * cols;
    double* result = (double*)malloc(maxSize * sizeof(double));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > i && j < cols - 1 - i) {
                result[(*resultSize)++] = matrix[i][j];
            }
        }
    }
    return result;
}

int countNegatives(double* array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int rows, cols;
    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);
    
    double** matrix = allocateMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    adjustRows(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    double totalSum = sumMatrix(matrix, rows, cols);
    printf("Сумма всех элементов матрицы: %.2lf\n", totalSum);

    int resultSize;
    double* aboveDiagonalArray = extractAboveDiagonals(matrix, rows, cols, &resultSize);

    int negativeCount = countNegatives(aboveDiagonalArray, resultSize);
    printf("Количество отрицательных элементов: %d\n", negativeCount);

    free(aboveDiagonalArray);
    freeMatrix(matrix, rows);

    return 0;
}
