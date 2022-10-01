#include "hous.hpp"

void Print(double** A, int n, int m){
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < m; j++) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
