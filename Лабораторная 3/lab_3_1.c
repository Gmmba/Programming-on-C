#include <stdio.h>

void main() {
	int gcd;
	int n1;
	int n2;
	printf("Enter number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	for(int i = 1; i <= n1 && i <= n2; i++) {
		if(n1 % i == 0 && n2 % i == 0) {
			gcd = i;
		}
	}
	printf("gcd is %d", gcd);
}
