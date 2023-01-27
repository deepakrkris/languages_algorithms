#include <iostream>
using namespace std;

void findClosestFraction(double decimal, int maxDenominator) {
    int closestNumerator = 1;
    int closestDenominator = 1;
    double closestDifference = abs(decimal - ((double) closestNumerator / closestDenominator));
    int numerator = closestNumerator;
    int denominator = closestDenominator;
    for (int i = 0; i < maxDenominator; i++) {
        if (((double) numerator / denominator) < decimal) {
            numerator++;
        } else {
            denominator++;
        }
        double difference = abs(decimal - ((double) numerator / denominator));
        if (difference < closestDifference) {
            closestNumerator = numerator;
            closestDenominator = denominator;
            closestDifference = difference;
        }
    }
    cout << closestNumerator << "/" << closestDenominator << endl;
}

int main() {
    double decimal = 3.14;
    int maxDenominator = 100;
    findClosestFraction(decimal, maxDenominator);
    decimal = 0.333;
    maxDenominator = 10;
    findClosestFraction(decimal, maxDenominator);
    decimal = 0.43;
    maxDenominator = 10;
    findClosestFraction(decimal, maxDenominator);
    return 0;
}
