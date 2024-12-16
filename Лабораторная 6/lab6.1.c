#include <stdio.h>

int main() {
    int arrA[10] = { 1, 2, 5, 7, 4, 8, 9, 3, 5, 0};
    int arrB[10] = { 6, -3, 2, 1, 0, 5, 3, -1, 7, 9};
    int arrC[10];
    int max;
    int zrs;
    float armn;
    
    for(int i=0; i<10; i++) {
        arrC[i] = arrA[i] + arrB[i];
    }
    for(int j=0; j<10; j+=2) {
        if(arrA[j] > max) {
            max = arrA[j];
        }
    }
    for(int k=1; k<11; k+=2) {
        if(arrB[k] < 0) {
            zrs++;
        }
    }
    for(int m=0; m<10; m++) {
        armn += arrC[0];
    }
    printf("Максимальная реальная часть массива A: %d\n", max);
    printf("Количество мнимых частей меньше нуля в массиве B: %d\n", zrs);
    printf("Среднее арифметическое всех элементов C: %.2f", armn/10);
}
