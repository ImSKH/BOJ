#include <stdio.h>

int main(void) {
  int N,K;
  scanf("%d %d",&N,&K);

  int Pe[N];
  for(int i=0; i<N;i++){
    Pe[i]=i+1;
  }
  for(int j=0; j<N; j++){
    printf("%d",Pe[j]);
  }
  for(int q=0; q<N+K; q+=K){
    if(q>=N) q=q-N;
    printf("%d ",Pe[q]);
  }
}
