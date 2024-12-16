#include <stdio.h>
#include "fraction.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void printFraction(Fraction frac) {
    int divisor = gcd(frac.a, frac.b);
    printf("%d/%d\n", frac.a / divisor, frac.b / divisor);
}

Fraction multiplyFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.a = f1.a * f2.a;
    result.b = f1.b * f2.b;
    return result;
}

Fraction divideFractions(Fraction f1, Fraction f2) {
    Fraction result;
    result.a = f1.a * f2.b;
    result.b = f1.b * f2.a;
    return result;
}
