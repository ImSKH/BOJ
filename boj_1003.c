#include <stdio.h>

int fibo_memo[50]={0,};

int fibo(int n){
  if(n<2) return n;
  if(fibo_memo[n]!=0) return fibo_memo[n];
  return fibo_memo[n]=fibo(n-1)+fibo(n-2);
}

int main(){
  int T,N,K;
  scanf("%d",&T);
  while(T){
    T--;
    scanf("%d",&N);
    if(N==0) printf("1 0\n");
    else if(N==1) printf("0 1\n");
    else if(N==2) printf("1 1\n");
    else{
      K=fibo(N);
      printf("%d %d\n",fibo_memo[N-1],K);
    }
  }
}
