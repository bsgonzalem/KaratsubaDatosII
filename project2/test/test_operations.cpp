
#include <iostream>
#include "../src/operations.h"

using namespace std;

int main() {

    cout << "BASIC OPERATIONS TESTS" << endl;

    cout << "\n1. Normalize" << endl;
    cout << "000123 -> " << normalize("000123") << endl;
    cout << "0000 -> " << normalize("0000") << endl;
    cout << "001050 -> " << normalize("001050") << endl;

    cout << "\n2. Addition" << endl;
    cout << "123 + 456 = " << add("123", "456") << endl;
    cout << "999 + 1 = " << add("999", "1") << endl;
    cout << "12345 + 678 = " << add("12345", "678") << endl;
    cout << "000123 + 000456 = " << add("000123", "000456") << endl;
    cout << "0 + 0 = " << add("0", "0") << endl;

    cout << "\n3. Subtraction" << endl;
    cout << "456 - 123 = " << subtract("456", "123") << endl;
    cout << "1000 - 1 = " << subtract("1000", "1") << endl;
    cout << "500 - 250 = " << subtract("500", "250") << endl;
    cout << "100 - 99 = " << subtract("100", "99") << endl;
    cout << "000456 - 000123 = " << subtract("000456", "000123") << endl;

    cout << "\n4. Shift" << endl;
    cout << "123 shifted by 1 = " << shift("123", 1) << endl;
    cout << "456 shifted by 2 = " << shift("456", 2) << endl;
    cout << "89 shifted by 3 = " << shift("89", 3) << endl;
    cout << "0 shifted by 3 = " << shift("0", 3) << endl;

    cout << "\n5. Split" << endl;

    auto parts1 = split("123456", 3);
    cout << "123456 -> High: " << parts1.first << ", Low: " << parts1.second << endl;

    auto parts2 = split("98765432", 4);
    cout << "98765432 -> High: " << parts2.first<< ", Low: " << parts2.second << endl;

    return 0;
}
