#include <stdio.h> // 16 Вариант
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int Y[] = {10, 20, 5, 3, 7}; // Создаем массив
    int size = sizeof(Y) / sizeof(Y[0]); // Размер массива
    bool is_sorted = true;

    
    for (int i = 0; i < size - 1; i++) { // Проверяем, отсортирован ли массив
        if (Y[i] > Y[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        printf("Массив уже упорядочен.");
        return 0;
    }

   
    int min_non_prime = -1; // Поиск минимального непростого числа
    for (int i = 0; i < size; i++) {
        bool is_prime = true;
        if (Y[i] < 2) {
            is_prime = false;
        } else {
            for (int j = 2; j * j <= Y[i]; j++) {
                if (Y[i] % j == 0) {
                    is_prime = false;
                    break;
                }
            }
        }

        if (!is_prime && (min_non_prime == -1 || Y[i] < min_non_prime)) {
            min_non_prime = Y[i];
        }
    }

    if (min_non_prime == -1) {
        printf("Массив состоит только из простых чисел.");
        return 0;
    }

    // Создаем массив, в котором после каждого второго элемента мин. непростое число
    int new_size = size + (size / 2); 
    int *new_Y = (int *)malloc(new_size * sizeof(int));
    int j = 0;

    for (int i = 0; i < size; i++) {
        new_Y[j++] = Y[i];
        if ((i + 1) % 2 == 0 && i + 1 < size) {
            new_Y[j++] = min_non_prime;
        }
    }

    // Выводим результат
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_Y[i]);
    }
    printf("\n");

    return 0;
}
