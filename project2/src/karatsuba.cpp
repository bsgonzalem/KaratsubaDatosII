#include "karatsuba.h"
#include "operations.h"

#include <algorithm>
#include <string>

using namespace std;

// Agrega ceros a la izquierda hasta alcanzar la longitud indicada.
static string padLeft(const string& A, int length) {
    if ((int)A.size() >= length) {
        return A;
    }

    return string(length - A.size(), '0') + A;
}

// Calcula el producto de dos números representados como cadenas.
static string karatsuba(const string& A, const string& B) {
    string a = normalize(A);
    string b = normalize(B);

    // Caso base: si alguno de los números es cero.
    if (a == "0" || b == "0") {
        return "0";
    }

    // Caso base: multiplicación de números de un solo dígito.
    if (a.size() == 1 && b.size() == 1) {
        int product = (a[0] - '0') * (b[0] - '0');
        return to_string(product);
    }

    // Igualar las longitudes y completar hasta una potencia de 2.
    int n = max(a.size(), b.size());
    int paddedLength = 1;

    while (paddedLength < n) {
        paddedLength *= 2;
    }

    a = padLeft(a, paddedLength);
    b = padLeft(b, paddedLength);

    int m = paddedLength / 2;

    // Dividir cada número en parte alta y parte baja.
    auto partsA = split(a, m);
    auto partsB = split(b, m);

    string highA = partsA.first;
    string lowA = partsA.second;

    string highB = partsB.first;
    string lowB = partsB.second;

    // Productos recursivos.
    string z2 = karatsuba(highA, highB);
    string z0 = karatsuba(lowA, lowB);

    // Producto de las sumas de las partes.
    string sumA = add(highA, lowA);
    string sumB = add(highB, lowB);

    string z1 = karatsuba(sumA, sumB);

    // Término intermedio: z1 - z2 - z0.
    string middle = subtract(z1, z2);
    middle = subtract(middle, z0);

    // Combinar los resultados:
    // z2 * 10^(2m) + middle * 10^m + z0.
    string result = add(
        add(shift(z2, 2 * m), shift(middle, m)),
        z0
    );

    return normalize(result);
}

// Función pública.
string karatsubaMultiply(const string& A, const string& B) {
    return karatsuba(A, B);
}