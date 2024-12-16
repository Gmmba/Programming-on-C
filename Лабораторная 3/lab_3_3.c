#include <stdio.h>

int main() {
	int a;
	printf("Введите число: ");
	scanf("%d", &a);
	if(a<2) {
		puts("0");
		return 0;
	}
	for(int n=2; n*n <= a; n++) {
		if(a%n == 0) {
			puts("0");
			return 0;
		}
	}
	puts("1);
}
