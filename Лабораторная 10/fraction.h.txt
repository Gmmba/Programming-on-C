#ifndef FRACTION_H
#define FRACTION_H

typedef struct {
    int a; // Числитель
    int b; // Знаменатель
} Fraction;

void printFraction(Fraction frac);
Fraction multiplyFractions(Fraction f1, Fraction f2);
Fraction divideFractions(Fraction f1, Fraction f2);

#endif
