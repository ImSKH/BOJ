#include <stdio.h>

int PrimeN(int N){
  if(N==1) return 0;
  else if(N==1) return 1;
  else{
    int cnt=0;
    for(int i=2; i<N; i++){
      if(N%i==0) cnt++;
    }
    if(cnt==0) return 1;
    else return 0;
  }
}

int main(){
  int T,N,cnt=0;
  scanf("%d",&T);
  for(int i=0; i<T; i++){
    scanf("%d",&N);
    if(PrimeN(N)==1) cnt++;
  }
  printf("%d",cnt);
}
