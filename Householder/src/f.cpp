#include "hous.hpp"

void f(double **A, int n){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i == j){
        A[i][j] = i + 1;
      } else if(((i - 1) == j) || ((i + 1 == j))){
        A[i][j] = 1;
      } else{
        A[i][j] = 0;
      }
    }
  }
}
