#include <stdio.h>
#include <math.h>
int main()
{
float x;
float y;
printf("Введите координаты точки(x, y): ");
scanf("%f %f",&x, &y);
if ((y <= 1) && (x <= 1) && (y >= -x)) {
	printf("Yes (%.2f, %.2f)\n", x, y);
} else {
	printf("No (%.2f, %.2f\n", x, y);
}
}
