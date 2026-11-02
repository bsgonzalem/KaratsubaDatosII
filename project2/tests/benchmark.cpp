#include "../src/classic.h"
#include "../src/karatsuba.h"

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

// Evita que el resultado de las multiplicaciones sea descartado.
volatile unsigned long long checksum = 0;

// Genera un número decimal de n cifras.
// La semilla fija permite repetir el experimento.
string generateNumber(int n, mt19937& generator) {
    uniform_int_distribution<int> firstDigit(1, 9);
    uniform_int_distribution<int> otherDigits(0, 9);

    string number;
    number.reserve(n);

    number += char('0' + firstDigit(generator));

    for (int i = 1; i < n; i++) {
        number += char('0' + otherDigits(generator));
    }

    return number;
}

double measureClassic(
    const string& A,
    const string& B,
    int repetitions
) {
    auto start = steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        string result = classicMultiply(A, B);

        checksum += result.front() + result.back();
    }

    auto end = steady_clock::now();

    return duration<double, micro>(end - start).count()
           / repetitions;
}

double measureKaratsuba(
    const string& A,
    const string& B,
    int repetitions
) {
    auto start = steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        string result = karatsubaMultiply(A, B);

        checksum += result.front() + result.back();
    }

    auto end = steady_clock::now();

    return duration<double, micro>(end - start).count()
           / repetitions;
}

int main() {
    vector<int> sizes = {
        16, 32, 64, 128, 256, 512, 1024
    };

    const int repetitions = 7;

    mt19937 generator(12345);

    cout << "digits,repetitions,classic_us,karatsuba_us"
         << endl;

    for (int n : sizes) {
        string A = generateNumber(n, generator);
        string B = generateNumber(n, generator);

        // Verificar que ambos algoritmos produzcan
        // el mismo resultado antes de medir.
        string classicResult = classicMultiply(A, B);
        string karatsubaResult = karatsubaMultiply(A, B);

        if (classicResult != karatsubaResult) {
            cerr << "Error: results differ for n = "
                 << n << endl;

            return 1;
        }

        // Calentamiento inicial.
        classicMultiply(A, B);
        karatsubaMultiply(A, B);

        double classicTime =
            measureClassic(A, B, repetitions);

        double karatsubaTime =
            measureKaratsuba(A, B, repetitions);

        cout << n << ","
             << repetitions << ","
             << classicTime << ","
             << karatsubaTime
             << endl;
    }

    cerr << "Checksum: " << checksum << endl;

    return 0;
}