#include "hous.hpp"

double** Aloc(int n){
  double** M;
  M = new double*[n];
  for (size_t i = 0; i < n; i++) {
    M[i] = new double[n];
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i == j){
        M[i][j] = 1;
      }
      else{
        M[i][j] = 0;
      }
    }
  }
  return M;
}

double* aloc(int n){
  double* vec;
  vec = new double[n];
  return vec;
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
