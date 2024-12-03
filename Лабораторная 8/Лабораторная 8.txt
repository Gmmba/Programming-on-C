#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

double determinant(double **matrix, int size) {
    if (size == 1) {
        return matrix[0][0];
    }
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    for (int col = 0; col < size; col++) {
        double **subMatrix = (double **)malloc((size - 1) * sizeof(double *));
        for (int i = 0; i < size - 1; i++) {
            subMatrix[i] = (double *)malloc((size - 1) * sizeof(double));
        }

        for (int i = 1; i < size; i++) {
            int subCol = 0;
            for (int j = 0; j < size; j++) {
                if (j == col) continue;
                subMatrix[i - 1][subCol++] = matrix[i][j];
            }
        }

        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(subMatrix, size - 1);

        for (int i = 0; i < size - 1; i++) {
            free(subMatrix[i]);
        }
        free(subMatrix);
    }
    return det;
}

void replaceColumn(double **matrix, double *column, int colIndex, int size) {
    for (int i = 0; i < size; i++) {
        matrix[i][colIndex] = column[i];
    }
}

int main() {
    int size;

    printf("Введите размер матрицы: ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE) {
        printf("Неверный размер матрицы. Допустимый диапазон: 1-%d.\n", MAX_SIZE);
        return 1;
    }

    double **A = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        A[i] = (double *)malloc(size * sizeof(double));
    }

    double *B = (double *)malloc(size * sizeof(double));

    printf("Введите элементы матрицы A (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Введите элементы столбца свободных членов B:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &B[i]);
    }

    double detA = determinant(A, size);

    if (detA == 0) {
        printf("Система не имеет единственного решения (определитель равен нулю).\n");
        for (int i = 0; i < size; i++) {
            free(A[i]);
        }
        free(A);
        free(B);
        return 1;
    }

    double *solution = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        double **tempMatrix = (double **)malloc(size * sizeof(double *));
        for (int j = 0; j < size; j++) {
            tempMatrix[j] = (double *)malloc(size * sizeof(double));
            for (int k = 0; k < size; k++) {
                tempMatrix[j][k] = A[j][k];
            }
        }

        replaceColumn(tempMatrix, B, i, size);

        double detTemp = determinant(tempMatrix, size);

        solution[i] = detTemp / detA;

        for (int j = 0; j < size; j++) {
            free(tempMatrix[j]);
        }
        free(tempMatrix);
    }

    printf("Решение системы:\n");
    for (int i = 0; i < size; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }

    for (int i = 0; i < size; i++) {
        free(A[i]);
    }
    free(A);
    free(B);
    free(solution);

    return 0;
}
