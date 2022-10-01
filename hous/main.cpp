#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#define eps 1e-15

double** Aloc(int n){
  double** M;
  M = new double*[n];
  for (size_t i = 0; i < n; i++) {
    M[i] = new double[n];
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i == j){
        M[i][j] = 1;
      }
      else{
        M[i][j] = 0;
      }
    }
  }
  return M;
}

double* aloc(int n){
  double* vec;
  vec = new double[n];
  return vec;
}

void Free(double** A, int n){
  for (size_t i = 0; i < n; i++) {
    if(A[i]){
      delete[] A[i];
    }
  }
  if(A){
    delete[] A;
  }
}

void Def(double** A, int n, const char* file_name){
  std::ifstream file(file_name);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      file >> A[i][j];
    }
  }
  file.close();
}

void Print(double** A, int n){
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cout << A[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

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
    //alpha = norm(x, n);
    x[index] -= alpha;
    double beta = norm(x, n);
    //beta = norm(x, n);
    for (size_t i = index; i < n; i++) {
      if (beta >= eps) {
        x[i] /= beta;
      }
      //x[i] /= beta;
    }
    //for (size_t i = 0; i < n; i++) {
      //std::cout << x[i] << '\n';
    //}
    //std::cout << '\n';
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
    //Print(P, n);
    //Print(Q, n);
    //Print(P, n);
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
  //std::cout << R[0][0] << '\n';
  for (size_t i = 0; i < n; i++) {
		double a = R[n - 1 - i][n - 1 - i];
		for (size_t l = 0; l < n; l++) {
      if (a >= eps) {
        Z[n - 1 - i][l] /= a;
      }
			//Z[n - 1 - i][l] /= a;
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
  Print(X, n);

  for (size_t i = 0; i < n; i++) {
    for (size_t j = i; j < n; j++) {
      double buf = Q[i][j];
      Q[i][j] = Q[j][i];
      Q[j][i] = buf;
    }
  }

  //Print(P, n);
  //Print(Q, n);
  //Print(R, n);
  //Print(X, n);
}

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
