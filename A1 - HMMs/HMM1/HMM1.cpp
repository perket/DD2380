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

  double* alpha = new double[T*N]();

	for(int i=0;i<N;i++){
		int o1 = O[0];
		alpha[i] = B[i * K + o1] * pi[i];
  }

  for(int t=1;t<T;t++){
    	for(int i=0;i<N;i++){
    		double alphaSum = .0;
    		for(int j=0;j<N;j++){
    			alphaSum += A[j * N + i] * alpha[(t-1) * N + j];
    		}
    		int ot = O[t];
    		alpha[t * N + i] = B[i * K + ot] * alphaSum;
    	}
	}

  double P = .0;

  for(int j=0;j<N;j++){
    P += alpha[(T-1) * N + j];
  }

  std::cout<<P<<std::endl;

  return 0;
}
