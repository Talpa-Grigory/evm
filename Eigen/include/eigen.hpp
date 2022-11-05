#ifndef eigen
#define eigen
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
void Print(double** A, int n, int m);
double norm(double* vec, int size);
void Eigen(double** Y, double** P, double** R, double* x, int n);
void f(double **A, int n);

#endif // eigen
