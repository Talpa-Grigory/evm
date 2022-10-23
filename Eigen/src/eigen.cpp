#include "eigen.hpp"

double norm(double* vec, int size){
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += vec[i] * vec[i];
  }
  return std::sqrt(sum);
}

void Eigen(double** A, double** Y, double** P, double** R, double* x, int n){
  std::cout << "P matrix" << '\n';
  Print(P, n, n);
  for (size_t index = 1; index < n - 1; index++) {
    for (size_t i = 0; i < n; i++) {
      if(i < index){
        x[i] = 0;
      }
      else{
        x[i] = Y[i][index - 1];
      }
    }
    double alpha = norm(x, n);
    x[index] -= alpha;
    double beta = norm(x, n);
    for (size_t i = index; i < n; i++) {
      if (beta >= eps) {
        x[i] /= beta;
      }
    }
    std::cout << "x_" << index << '\n';
    for (size_t i = 0; i < n; i++) {
      std::cout << x[i] << '\n';
    }
    std::cout << '\n';
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
    std::cout << "P_" << index << '\n';
    Print(P, n, n);

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        double sum = 0;
        for (size_t k = 0; k < n; k++) {
          sum += P[i][k] * Y[k][j];
        }
        R[i][j] = sum;
      }
    }
    std::cout << "R_1_" << index << '\n';
    Print(R, n, n);

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        Y[i][j] = R[i][j];
      }
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        double sum = 0;
        for (size_t k = 0; k < n; k++) {
          sum += Y[i][k] * P[k][j];
        }
        R[i][j] = sum;
      }
    }

    std::cout << "R_2_" << index << '\n';
    Print(R, n, n);

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        Y[i][j] = R[i][j];
      }
    }
  }
  Print(R, n, n);
}
