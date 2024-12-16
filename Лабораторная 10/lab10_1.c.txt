#include <stdio.h>
#include "fraction.h"

int main() {
    Fraction frac1 = {2, 3};
    Fraction frac2 = {3, 4};

    printf("Первая дробь: ");
    printFraction(frac1);
    printf("Вторая дробь: ");
    printFraction(frac2);

    Fraction result = multiplyFractions(frac1, frac2);
    printf("Результат умножения: ");
    printFraction(result);

    result = divideFractions(frac1, frac2);
    printf("Результат деления: ");
    printFraction(result);

    return 0;
}
