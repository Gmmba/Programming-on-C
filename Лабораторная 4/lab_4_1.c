#include <stdio.h>

int main() {
	int i, j;
	// Первые 4 строки	
	for(i = 7; 1 >= 1; i -= 2) {
		for(j = 0; j < i; j++) {
			printf("O");
		}
		printf("\n");
	}
	// Последние 3 строки
	for(i = 3; i <= 7; i += 2) {
		for(j = 0; j < i; j++) {
			printf("O");
		}
		printf("\n");
	}
}
