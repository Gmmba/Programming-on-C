#include <stdio.h>

void main() {
	int a;
	int b;
	int n1;
	printf("Первое число: ");
	scanf("%d", &a);
	printf("Второе число: ");
	scanf("%d", &b);

	for(int n = 1; n%a != 0 || n%b != 0; n++) {
		n1 = n+1;
	}
	printf("Наименьшее общее делимое: %d", n1);
}
