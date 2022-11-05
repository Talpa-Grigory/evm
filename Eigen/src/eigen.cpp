#include "eigen.hpp"

double norm(double* vec, int size){
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += vec[i] * vec[i];
  }
  return std::sqrt(sum);
}

void Hessenberg(double** Y, double** P, double** R, double* x, int n){
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

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        double sum = 0;
        for (size_t k = 0; k < n; k++) {
          sum += P[i][k] * Y[k][j];
        }
        R[i][j] = sum;
      }
    }
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
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        Y[i][j] = R[i][j];
      }
    }
  }
}

void Eigen(double** Q, double** Y, double** P, double** R, double* x, int n){
  Hessenberg(Y, P, R, x, n);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i == j){
        P[i][j] = 1;
      }
      else {
        P[i][j] = 0;
      }
    }
  }
  Print(Y, n, n);
  for (size_t k = 0; k < 10000; k++) {
    for (size_t index = 0; index < n - 1; index++) {
      double elem_i_i = Y[index][index];
      double elem_i_j = Y[index + 1][index];
      double cos = elem_i_i / (std::sqrt(elem_i_i * elem_i_i + elem_i_j * elem_i_j));
      double sin = -elem_i_j / (std::sqrt(elem_i_i * elem_i_i + elem_i_j * elem_i_j));
      for (size_t i = 0; i < n; i++) {
        R[index][i] = cos * Y[index][i] - sin * Y[index + 1][i];
        R[index + 1][i] = sin * Y[index][i] + cos * Y[index + 1][i];
      }
      for (size_t i = 0; i < n; i++) {
        Y[index][i] = R[index][i];
        Y[index + 1][i] = R[index + 1][i];
      }
      for (size_t i = 0; i < n; i++) {
        Q[i][index] = cos * P[i][index] - sin * P[i][index + 1];
        Q[i][index + 1] = sin * P[i][index] + cos * P[i][index + 1];
      }
      for (size_t i = 0; i < n; i++) {
        P[i][index] = Q[i][index];
        P[i][index + 1] = Q[i][index + 1];
      }
    }
    for (size_t i = 0; i < n; i++) {
      Q[i][n - 1] *= -1;
    }
    R[n - 1][n - 1] *= -1;

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        double sum = 0;
        for (size_t l = 0; l < n; l++) {
          sum += R[i][l] * Q[l][j];
        }
        Y[i][j] = sum;
      }
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        R[i][j] = Y[i][j];
      }
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if(i == j){
          P[i][j] = 1;
          Q[i][j] = 1;
        }
        else {
          P[i][j] = 0;
          Q[i][j] = 0;
        }
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    std::cout << "\u03BB_" << i << " = " << Y[i][i] << '\n';
  }
  std::cout << '\n';
}
