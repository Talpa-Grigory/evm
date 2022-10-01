#include "hous.hpp"

double norm(double* vec, int size){
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += vec[i] * vec[i];
  }
  return std::sqrt(sum);
}

void Hous(double** A, double** X, double** Y, double** Z, double** P, double** Q, double** R, double* x, int n){
  for (size_t index = 0; index < n ; index++) {
    for (size_t i = 0; i < n; i++) {
      if(i < index){
        x[i] = 0;
      }
      else{
        x[i] = Y[i][index];
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
        double sum = 0;
        for (size_t k = 0; k < n; k++) {
          sum += P[i][k] * X[k][j];
        }
        Q[i][j] = sum;
      }
    }
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        X[i][j] = Q[i][j];
        Y[i][j] = R[i][j];
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
	   double a = R[n - 1 - i][n - 1 - i];
		for (size_t l = 0; l < n; l++) {
      if (a >= eps) {
        Z[n - 1 - i][l] /= a;
      }
		}
		for (size_t j = 0; j < n - 1 - i; j++) {
			double b = R[j][n - 1 - i];
			for (size_t k = 0; k < n; k++) {
				Z[j][k] -= b * Z[n - 1 - i][k];
			}
		}
	 }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      double sum = 0;
      for (size_t k = 0; k < n; k++) {
        sum += Z[i][k] * Q[k][j];
      }
      X[i][j] = sum;
    }
  }
}
