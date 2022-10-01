#include "hous.hpp"

void Print(double** A, int n){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
