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
  } else if(argc == 2) {
    A = Aloc(n);
    Y = Aloc(n);
    f(A, n);
    f(Y, n);
  }
  X = Aloc(n);
  Z = Aloc(n);
  P = Aloc(n);
  Q = Aloc(n);
  R = Aloc(n);
  x = aloc(n);

  int start_time = clock();

  Hous(A, X, Y, Z, P, Q, R, x, n);

  int end_time = clock();

  Print(X, n, 10);
  std::cout << "time: " << end_time - start_time << " ms" << '\n';
  std::cout << "residual: " << std::setprecision(15) << Res(A, X, Y, n) << '\n';

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
