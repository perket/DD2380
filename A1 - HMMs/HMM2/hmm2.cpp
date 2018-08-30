#include <iostream>
#include <cmath>
#include <vector>

int main(){
  int N=0;
  int K=0;
  int T=0;
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

  std::cin>>T;
  int* O = new int[T]();
  for(int i=0;i<T;i++){
    std::cin>>O[i];
  }

  double* delta = new double[T*N]();
  int* deltaIdx = new int[T*N]();

	for(int i=0;i<N;i++){
		int o1 = O[0];
		delta[i] = B[i * K + o1] * pi[i];
  }

  for(int t=1;t<T;t++){
    int ot = O[t];
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
        double d = A[j * N + i] * delta[(t-1) * N + j] * B[i * K + ot];
        if(d > delta[t * N + i]){
          delta[t * N + i] = d;
          deltaIdx[t * N + i] = j;
        }
    	}
    }
	}

  int* Xstar = new int[T]();
  for(int j=0;j<N;j++){
    double Pmax = .0;
    if(delta[(T-1) * N +j] > Pmax){
      Xstar[T-1] = j;
    }
  }

  for(int t=(T-2);t>=0;t--){
    Xstar[t] = deltaIdx[(t+1) * N + Xstar[t+1]];
  }

  for(int t=0;t<T;t++){
    std::cout<<Xstar[t]<<" ";
  }

  return 0;
}
