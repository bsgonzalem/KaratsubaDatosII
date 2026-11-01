
#include "classic.h"
#include "operations.h"

string classicMultiply(const string& A, const string& B) {

    string numA = normalize(A);
    string numB = normalize(B);

    if (numA == "0" || numB == "0") {
        return "0";
    }

    int n = numA.length();
    int m = numB.length();

    string result(n + m, '0');

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {

            int digitA = numA[i] - '0';
            int digitB = numB[j] - '0';

            int product = digitA * digitB;

            int position1 = i + j;
            int position2 = i + j + 1;

            int sum = product + (result[position2] - '0');

            result[position2] = (sum % 10) + '0';
            result[position1] += sum / 10;
        }
    }

    return normalize(result);
}
