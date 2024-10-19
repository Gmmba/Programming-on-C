#include <string.h>
#include <stdio.h>

int main() {
    int a;
    printf("Введите число: ");
    scanf("%d", &a);
    char even[50] = "";
    char odd[50] = "";

    int i = 1;
    while (a != 0) {
        if (i % 2 != 0) {
            if (a & 1) {
                strcat(odd, "1");
            } else {
                strcat(odd, "0");
            }
        } else {
            if (a & 1) {
                strcat(even, "1");
            } else {
                strcat(even, "0");
            }
        }
        a >>= 1;
        i++;
    }

    printf("Even: %s\n", even);
    printf("Odd: %s\n", odd);
    return 0;
}
