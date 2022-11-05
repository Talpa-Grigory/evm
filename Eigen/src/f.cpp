#include "eigen.hpp"

void f(double **A, int n){
  double k = n;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if((i == j)){
        if((i != n-1) && (i != 0)){
          A[i][j] = -2;
        } else if(i == 0){
          A[i][j] = -1;
          }
          else if(i == n-1){
            A[i][j] = -(k-1)/k;
          }
      } else if(((i - 1) == j) || ((i + 1 == j))){
        A[i][j] = 1;
      } else{
        A[i][j] = 0;
      }
    }
  }
}
