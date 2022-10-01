#ifndef hous
#define hous
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#define eps 1e-15

double** Aloc(int n);
double* aloc(int n);
void Def(double** A, int n, const char* file_name);
void Free(double** A, int n);
void Print(double** A, int n);
double norm(double* vec, int size);
void Hous(double** A, double** X, double** Y, double** Z, double** P, double** Q, double** R, double* x, int n);

#endif // hous
