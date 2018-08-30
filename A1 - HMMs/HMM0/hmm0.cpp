#include <iostream>
#include <cmath>
#include <vector>

double* mult(int X, int Y, int Z, double* A, double* B){
  double* res = new double[Y*Z]();
  for(int i=0;i<X;i++){
    for(int j=0;j<Z;j++){
      for(int k=0;k<Y;k++){
        res[i * Z + j] = res[i * Z + j] + A[i * Y + k] * B[k * Z + j];
      }
    }
  }


  return res;
}

int main(){
  int N=0;
  int K=0;
  int rowHeight = 1;

  std::cin>>N>>N;

  double* A = new double[N*N]();

  for(int i=0;i<N*N;i++){
    std::cin>>A[i];
  }

  std::cin>>N>>K;

  double* B = new double[N*K]();

  for(int i=0;i<N*K;i++){
    std::cin>>B[i];
  }

  std::cin>>rowHeight>>N;

  double* pi = new double[N]();

  for(int i=0;i<N;i++){
    std::cin>>pi[i];
  }

  double* Api = mult(1, N, N, pi, A);
  double* O = mult(1,N,K,Api,B);
  std::cout<<1<<" "<<K<<" ";
  for(int i=0;i<K;i++){
    std::cout<<O[i]<<" ";
  }

  return 0;
}
