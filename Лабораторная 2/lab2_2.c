#include  <stdio.h>
int main() 
{
int a;
printf("Введите год: ");
scanf("%d", &a);
if (a % 400 == 0) {
	printf("yes %d\n", a);
} else if (a % 100 == 0) {
	printf("no %d\n", a);
} else if (a % 4 == 0) {
	printf("yes %d\n", a);
} else {
	printf("yes %d\n", a);
}
}
