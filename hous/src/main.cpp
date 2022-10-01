#include "hous.hpp"

int main(int argc, char *argv[]){
  std::stringstream convert(argv[1]);
  int n;
  convert >> n;
  double **A;
  double **X;
  double **Y;
  double **Z;
  double **P;
  double **Q;
  double **R;
  double *x;

  if (argc == 3) {
    A = Aloc(n);
    Y = Aloc(n);
    Def(A, n, argv[2]);
    Def(Y, n, argv[2]);
  }
  X = Aloc(n);
  Z = Aloc(n);
  P = Aloc(n);
  Q = Aloc(n);
  R = Aloc(n);
  x = aloc(n);

  Hous(A, X, Y, Z, P, Q, R, x, n);

  Print(A, n);
  //Print(X, n);
  Free(A, n);
  Free(X, n);
  Free(Y, n);
  Free(Z, n);
  Free(P, n);
  Free(Q, n);
  Free(R, n);
  delete[] x;
  return 0;
}
