#include <stdio.h>

int main() {
	unsigned int a;
	printf("Введите число: ");
	scanf("%u", &a);

	int ones = 0;
	int zeros = 0;

	unsigned int num = a;

	// Проходим по каждому биту числа
	while (num > 0) {
    		if (num & 1) {
            		ones++;
        	} else {
            		zeros++;
        	}
        	num >>= 1;
    	}
	printf("Нули: %d\n", zeros);
	printf("Единицы: %d\n", ones);
}
