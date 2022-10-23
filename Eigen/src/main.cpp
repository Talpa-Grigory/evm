#include "eigen.hpp"

int main(int argc, char *argv[]){
  std::stringstream convert(argv[1]);
  int n;
  convert >> n;
  double **A;
  double **Y;
  double **P;
  double **R;
  double *x;

  if (argc == 3) {
    A = Aloc(n);
    Y = Aloc(n);
    Def(A, n, argv[2]);
    Def(Y, n, argv[2]);
  } else if(argc == 2) {
    A = Aloc(n);
    Y = Aloc(n);
    f(A, n);
    f(Y, n);
  }
  P = Aloc(n);
  R = Aloc(n);
  x = aloc(n);

  Print(A, n, n);
  Eigen(Y, P, R, x, n);

  Free(A, n);
  Free(Y, n);
  Free(P, n);
  Free(R, n);
  delete[] x;

  return 0;
}
