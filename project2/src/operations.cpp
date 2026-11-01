#include "operations.h"
#include <algorithm>


string normalize(const string& A) {

    int start = 0;

    while (start < A.length() - 1 && A[start] == '0') {
        start++;
    }

    return A.substr(start);
}

string add(const string& A, const string& B) {

    string result = "";

    int i = A.size() - 1;
    int j = B.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {

        int digitA = (i >= 0) ? A[i] - '0' : 0;
        int digitB = (j >= 0) ? B[j] - '0' : 0;

        int sum = digitA + digitB + carry;

        result += to_string(sum % 10);

        carry = sum / 10;

        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    return normalize(result);
}

