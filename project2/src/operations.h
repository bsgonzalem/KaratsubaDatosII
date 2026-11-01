#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <utility>

using namespace std;

string add(const string& A, const string& B);

string subtract(const string& A, const string& B);

string shift(const string& A, int k);

pair<string, string> split(const string& A, int m);

string normalize(const string& A);

#endif
