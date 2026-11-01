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

string subtract(const string& A, const string& B) {

    string result = "";

    int i = A.size() - 1;
    int j = B.size() - 1;
    int borrow = 0;

    while (i >= 0) {

        int digitA = A[i] - '0' - borrow;
        int digitB = (j >= 0) ? B[j] - '0' : 0;

        borrow = 0;

        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        }

        int difference = digitA - digitB;

        result += to_string(difference);

        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    return normalize(result);
}

string shift(const string& A, int k) {

    string result = A;

    for (int i = 0; i < k; i++) {
        result.append("0");
    }

    return normalize(result);
}

pair<string, string> split(const string& A, int m) {

    string high = A.substr(0, A.length() - m);
    string low = A.substr(A.length() - m);

    return {normalize(high), normalize(low)};
}
