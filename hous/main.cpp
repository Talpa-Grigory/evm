#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

double** Aloc(int n){
  double** M;
  M = new double*[n];
  for (size_t i = 0; i < n; i++) {
    M[i] = new double[n];
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
  return M;
}

double* aloc(int n){
  double* vec;
  vec = new double[n];
  return vec;
}

void Free(double** A, int n){
  for (size_t i = 0; i < n; i++) {
    if(A[i]){
      delete[] A[i];
    }
  }
  if(A){
    delete[] A;
  }
}

void Def(double** A, int n, const char* file_name){
  std::ifstream file(file_name);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      file >> A[i][j];
    }
  }
  file.close();
}

void Print(double** A, int n){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

double norm(double* vec, int size){
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += vec[i] * vec[i];
  }
  return std::sqrt(sum);
}

void Hous(double** A, double** X, double** P, double* x, int n){
  for (size_t i = 0; i < n; i++) {
    x[i] = A[i][0];
  }
  double alpha;
  alpha = norm(x, n);
  x[0] -= alpha;
  double beta;
  beta = norm(x, n);
  for (size_t i = 0; i < n; i++) {
    x[i] /= beta;
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i == j){
        P[i][j] = 1 - 2 * x[i] * x[j];
      }
      else{
        P[i][j] = -2 * x[i] * x[j];
      }
    }
  }
  Print(P, n);

}

int main(int argc, char *argv[]){
  std::stringstream convert(argv[1]);
  int n;
  convert >> n;
  double **A;
  double **X;
  double **P;
  double *x;

  if (argc == 3) {
    A = Aloc(n);
    X = Aloc(n);
    P = Aloc(n);
    Def(A, n, argv[2]);
  }
  x = aloc(n);

  Hous(A, X, P, x, n);

  Print(A, n);
  Print(X, n);
  Free(A, n);
  Free(X, n);
  Free(P, n);
  delete[] x;
  return 0;
}
