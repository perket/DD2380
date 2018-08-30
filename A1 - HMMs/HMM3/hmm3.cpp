#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>


void alphaPass(double* alpha, double* A, double* B, double* pi, int* O, double* c, int K, int N, int T){
  c[0] = 0;
  for(int i=0;i<N;i++){
    int o1 = O[0];
    alpha[0 * N + i] = pi[i] * B[i * K + o1];
    c[0] += alpha[0 * N + i];
  }
  c[0] = 1 / c[0];
  for(int i=0;i<N;i++){
    alpha[0 * N + i] *= c[0];
  }

  for(int t=1;t<T;t++){
    c[t] = 0;
    for(int i=0;i<N;i++){
      alpha[t * N + i] = 0;
      for(int j=0;j<N;j++){
        //alphaCurr[t][i] += (alphaCurr[t - 1][j] * txnMatrix[j][i]);
        alpha[t * N + i] += (alpha[(t-1) * N + j] * A[j * N + i]);
      }
      int ot = O[t];
      alpha[t * N + i] *= B[i * K + ot];
      c[t] += alpha[t * N + i];
    }

    c[t] = 1 / c[t];
    for(int i=0;i<N;i++){
      alpha[t * N + i] *= c[t];
    }
  }
}


void betaPass(double* beta, int* O, double* A, double* B, double* c, int K, int N, int T){
  for(int i=0;i<N;i++){
    beta[(T-1) * N + i] = c[T-1];
  }

  for(int t=T-2;t>=0;t--){
    for(int i=0;i<N;i++){
      beta[t * N + i] = 0;
      for(int j=0;j<N;j++){
        int ot = O[t+1];
        beta[t * N + i] += (A[i * N + j] * B[j * K + ot] * beta[(t+1) * N + j]);
      }
      beta[t * N + i] *= c[t];
    }
  }
}


void calcGammas(double* diGamma, double* gamma, double* alpha, double* beta, double* A, double* B, int* O, int K, int N, int T){
  double alphaSum;
  for(int t=0; t<T-1;t++){
    alphaSum = 0;
    for(int k=0;k<N;k++){
      for(int j=0;j<N;j++){
        int ot = O[t+1];
        alphaSum += (alpha[t * N + k] * A[k * N + j] * B[j * K + ot] * beta[(t+1) * N + j]);
      }
    }
    int ot = O[t+1];
    for(int i=0;i<N;i++){
      gamma[t * N + i] = 0;
      for(int j=0;j<N;j++){

        diGamma[t * N * N + i * N + j] = (alpha[t * N + i] * A[i * N + j] * B[j * K + ot] * beta[(t+1) * N + j]) / alphaSum;
        gamma[t * N + i] += diGamma[t * N * N + i * N + j];
      }
    }
  }

  alphaSum = 0;
  for(int i=0;i<N;i++){
    alphaSum += alpha[(T-1) * N + i];
  }

  for(int i=0;i<N;i++){
    gamma[(T-1) * N + i] = alpha[(T-1) * N + i] / alphaSum;
  }


}


void calcA(double* A, double* diGamma, double* gamma, int N, int T){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      double diGammaSum = 0;
      double gammaSum = 0;
      for(int t=0;t<T-1;t++){
        diGammaSum += diGamma[t * N * N + i * N + j];
        gammaSum += gamma[t * N + i];
      }
      A[i * N + j] = diGammaSum / gammaSum;
    }
  }
}


void calcB(double* B, double* gamma, int* O, int K, int N, int T){

  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      double gammaNumer = 0;
      double gammaDenom = 0;
      for(int t=0;t<T;t++){
        if(O[t] == j){
          gammaNumer += gamma[t * N + i];
        }
        gammaDenom += gamma[t * N + i];
      }
      B[i * K + j] = gammaNumer / gammaDenom;
    }
  }
}


void calcPi(double* pi, double* gamma, int N){
  for(int i=0;i<N;i++){
    pi[i] = gamma[0 * N + i];
  }
}

int main(){
  int N;
  int K;
  int T;
  int rowHeight;

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

  double* beta = new double[T*N]();
  double* alpha = new double[T*N]();
  double* diGamma = new double[T*N*N]();
  double* gamma = new double[T*N]();

  double logProb = INT_MIN+1;
  double prevLogProb = INT_MIN;
  int i = 0;

  while(i < 500  && logProb > prevLogProb){
    double* c = new double[T]();
    alphaPass(alpha, A, B, pi, O, c, K, N, T);
    betaPass(beta, O, A, B, c, K, N, T);
    calcGammas(diGamma, gamma, alpha, beta, A, B, O, K, N, T);
    calcPi(pi, gamma, N);
    calcA(A, diGamma, gamma, N, T);
    calcB(B, gamma, O, K, N, T);

    prevLogProb=logProb;
    logProb = 0;
    for(int t=0; t<T;t++) {
      logProb += log(c[t]);
    }
    logProb = -logProb;
    i++;

  }

  std::cout<<N<<" "<<N<<" ";
  for(int i=0;i<N*N;i++){
    std::cout<<A[i]<<" ";
  }
  std::cout<<std::endl<<N<<" "<<K<<" ";
  for(int i=0;i<N*K;i++){
    std::cout<<B[i]<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
