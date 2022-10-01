#include "hous.hpp"

double Res(double **A, double **X, double **Z, int n){
  double sum = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      sum = 0;
      for (size_t k = 0; k < n; k++) {
        sum += A[i][k] * X[k][j];
      }
      if(i == j){
        Z[i][j] = sum - 1;
      }
      else{
        Z[i][j] = sum;
      }
    }
  }
  sum = 1e-30;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      sum += abs(Z[i][j]) * abs(Z[i][j]);
    }
  }
  return sqrt(sum);
}
