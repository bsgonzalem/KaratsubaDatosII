
#include <iostream>
#include <cassert>
#include <string>
#include <utility>

#include "operations.h"

using namespace std;

int main() {

    cout << "====================================" << endl;
    cout << "  PRUEBAS DE OPERACIONES AUXILIARES" << endl;
    cout << "====================================" << endl;

    // 1. Pruebas de normalize()
    cout << "\n1. Probando normalize()..." << endl;

    assert(normalize("000123") == "123");
    assert(normalize("001050") == "1050");
    assert(normalize("0000") == "0");
    assert(normalize("123") == "123");

    cout << "normalize(): OK" << endl;


    // 2. Pruebas de add()
    cout << "\n2. Probando add()..." << endl;

    assert(add("123", "456") == "579");
    assert(add("999", "1") == "1000");
    assert(add("12345", "678") == "13023");
    assert(add("000123", "000456") == "579");
    assert(add("0", "0") == "0");
    assert(add("9999", "9999") == "19998");

    cout << "add(): OK" << endl;


    // 3. Pruebas de subtract()
    cout << "\n3. Probando subtract()..." << endl;

    assert(subtract("456", "123") == "333");
    assert(subtract("1000", "1") == "999");
    assert(subtract("500", "250") == "250");
    assert(subtract("100", "99") == "1");
    assert(subtract("000456", "000123") == "333");
    assert(subtract("1000", "1000") == "0");

    cout << "subtract(): OK" << endl;


    // 4. Pruebas de shift()
    cout << "\n4. Probando shift()..." << endl;

    assert(shift("123", 1) == "1230");
    assert(shift("456", 2) == "45600");
    assert(shift("89", 3) == "89000");
    assert(shift("0", 3) == "0");
    assert(shift("123", 0) == "123");

    cout << "shift(): OK" << endl;


    // 5. Pruebas de split()
    cout << "\n5. Probando split()..." << endl;

    auto parts1 = split("123456", 3);

    assert(parts1.first == "123");
    assert(parts1.second == "456");

    auto parts2 = split("98765432", 4);

    assert(parts2.first == "9876");
    assert(parts2.second == "5432");

    auto parts3 = split("00123", 2);

    assert(parts3.first == "1");
    assert(parts3.second == "23");

    cout << "split(): OK" << endl;


    cout << "\n====================================" << endl;
    cout << "TODAS LAS PRUEBAS PASARON CORRECTAMENTE" << endl;
    cout << "====================================" << endl;

    return 0;
}
