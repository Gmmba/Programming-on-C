#include  <stdio.h>
int main() 
{
float a;
char b;
printf("Введите температуру и единицу измерения('C' Цельсий или 'F' Фаренгейт): ");
scanf("%e", &a);
scanf("%c", &b);
if (b == 'C' || b == 'c') {
	printf("%f", a * 1.8 + 32);
} else if (b == 'F'|| b == 'f') {
	printf("%f", (a-32)/1.8);
} else {
	printf("Ошибка");
}
}
