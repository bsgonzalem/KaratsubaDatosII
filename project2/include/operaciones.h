#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>
#include <utility>

using namespace std;

string sumar(const string& A, const string& B);

string restar(const string& A, const string& B);

string desplazar(const string& A, int k);

pair<string, string> partir(const string& A, int m);

#endif
