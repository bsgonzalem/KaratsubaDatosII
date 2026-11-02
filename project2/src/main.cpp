#include <iostream>
#include <chrono>

#include "operations.h"
#include "classic.h"

//Pruebas
#include "karatsuba.h"
#include <cassert>
#include <string>
//Pruebas
using namespace std;

int main() {

    cout << "practica II" << endl;
    

//Temporal Commit 2
cout << "\n7. Testing Karatsuba multiplication:" << endl;

cout << "123 * 456 = "
     << karatsubaMultiply("123", "456") << endl;

cout << "99 * 99 = "
     << karatsubaMultiply("99", "99") << endl;

cout << "1000 * 25 = "
     << karatsubaMultiply("1000", "25") << endl;

cout << "123 * 0 = "
     << karatsubaMultiply("123", "0") << endl;

cout << "000123 * 0045 = "
     << karatsubaMultiply("000123", "0045") << endl;

cout << "123456789 * 987654321 = "
     << karatsubaMultiply("123456789", "987654321") << endl;
//Temporal Commit 2
    cout << "====================================" << endl;
    cout << "   PRACTICA 2 - KARATSUBA TESTS" << endl;
    cout << "====================================" << endl;

    // 1. Testing normalize
    cout << "\n1. Testing normalize:" << endl;

    cout << "000123 -> " << normalize("000123") << endl;
    cout << "0000 -> " << normalize("0000") << endl;
    cout << "001050 -> " << normalize("001050") << endl;

    // 2. Testing addition
    cout << "\n2. Testing addition:" << endl;

    cout << "123 + 456 = " << add("123", "456") << endl;
    cout << "999 + 1 = " << add("999", "1") << endl;
    cout << "12345 + 678 = " << add("12345", "678") << endl;
    cout << "000123 + 000456 = " << add("000123", "000456") << endl;
    cout << "0 + 0 = " << add("0", "0") << endl;

    // 3. Testing subtraction
    cout << "\n3. Testing subtraction:" << endl;

    cout << "456 - 123 = " << subtract("456", "123") << endl;
    cout << "1000 - 1 = " << subtract("1000", "1") << endl;
    cout << "500 - 250 = " << subtract("500", "250") << endl;
    cout << "100 - 99 = " << subtract("100", "99") << endl;
    cout << "000456 - 000123 = " << subtract("000456", "000123") << endl;

    // 4. Testing shift
    cout << "\n4. Testing shift:" << endl;

    cout << "123 shifted by 1 = " << shift("123", 1) << endl;
    cout << "456 shifted by 2 = " << shift("456", 2) << endl;
    cout << "89 shifted by 3 = " << shift("89", 3) << endl;
    cout << "0 shifted by 3 = " << shift("0", 3) << endl;

    // 5. Testing split
    cout << "\n5. Testing split:" << endl;

    auto parts1 = split("123456", 3);

    cout << "123456 -> High: " << parts1.first
         << ", Low: " << parts1.second << endl;

    auto parts2 = split("98765432", 4);

    cout << "98765432 -> High: " << parts2.first
         << ", Low: " << parts2.second << endl;

    // 6. Testing classic multiplication
    cout << "\n6. Testing classic multiplication:" << endl;

    cout << "123 * 456 = " << classicMultiply("123", "456") << endl;
    cout << "99 * 99 = " << classicMultiply("99", "99") << endl;
    cout << "1000 * 25 = " << classicMultiply("1000", "25") << endl;
    cout << "123 * 0 = " << classicMultiply("123", "0") << endl;
    cout << "000123 * 0045 = " << classicMultiply("000123", "0045") << endl;

    cout << "\n====================================" << endl;
    cout << "          TESTS COMPLETED" << endl;
    cout << "====================================" << endl;

/// TESTING 2
cout << "\n8. General correctness tests:" << endl;

// Casos con distintas longitudes y ceros.
assert(karatsubaMultiply("7", "8") == "56");
assert(karatsubaMultiply("9", "9") == "81");
assert(karatsubaMultiply("00012", "0003") == "36");
assert(karatsubaMultiply("1005", "20") == "20100");
assert(karatsubaMultiply("12345", "678") == "8369910");
assert(karatsubaMultiply("1234567", "89") == "109876463");

// Comparar Karatsuba contra la multiplicación clásica.
auto checkBoth = [](const string& A, const string& B) {
    string resultKaratsuba = karatsubaMultiply(A, B);
    string resultClassic = classicMultiply(A, B);

    assert(resultKaratsuba == resultClassic);
};

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

// Otro caso grande con ceros internos.
string bigC = "1" + string(150, '0') + "123456789";
string bigD = "987654321" + string(100, '0') + "7";

checkBoth(bigC, bigD);

cout << "All general correctness tests passed!" << endl;

    return 0;
}
