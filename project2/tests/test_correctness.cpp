#include "../src/classic.h"
#include "../src/karatsuba.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void checkBoth(const string& A, const string& B) {
    string resultKaratsuba = karatsubaMultiply(A, B);
    string resultClassic = classicMultiply(A, B);

    assert(resultKaratsuba == resultClassic);
}

int main() {
    cout << "Starting general correctness tests..." << endl;

    // Casos pequeños y casos límite.
    assert(karatsubaMultiply("7", "8") == "56");
    assert(karatsubaMultiply("9", "9") == "81");
    assert(karatsubaMultiply("00012", "0003") == "36");
    assert(karatsubaMultiply("1005", "20") == "20100");
    assert(karatsubaMultiply("12345", "678") == "8369910");
    assert(karatsubaMultiply("1234567", "89") == "109876463");

    // Longitudes diferentes.
    checkBoth("123456789012345", "987654321");
    checkBoth("12345678901234567890", "12345");

    // Ceros internos y ceros iniciales.
    checkBoth("1000000000000001", "9000000000000009");
    checkBoth("000001234567890", "000000987654321");

    // Longitudes impares.
    checkBoth("123456789", "987654321");
    checkBoth("123456789012345", "987654321098765");

    // Números de varios cientos de dígitos.
    string bigA(300, '9');
    string bigB(250, '8');

    checkBoth(bigA, bigB);

    // Números grandes con ceros internos.
    string bigC = "1" + string(150, '0') + "123456789";
    string bigD = "987654321" + string(100, '0') + "7";

    checkBoth(bigC, bigD);

    cout << "All general correctness tests passed!" << endl;

    return 0;
}