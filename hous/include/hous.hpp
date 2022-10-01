#ifndef hous
#define hous
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <iomanip>

#define eps 1e-16

double** Aloc(int n);
double* aloc(int n);
void Def(double** A, int n, const char* file_name);
void Free(double** A, int n);
void Print(double** A, int n, int m=3);
double norm(double* vec, int size);
void Hous(double** A, double** X, double** Y, double** Z, double** P, double** Q, double** R, double* x, int n);
double Res(double **A, double **X, double **Z, int n);
void f(double **A, int n);

#endif // hous
