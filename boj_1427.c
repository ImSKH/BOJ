#include <stdio.h>
#include <stdlib.h>
int Pow(int x,int y){
  if(y==0) return 1;
  return x*Pow(x,y-1);
}
int main(void) {
  int N=0,cnt=0,N0;
  int *d;
  scanf("%d",&N);
  N0=N;
  while(N0>0){
    N0/=10;
    cnt++;
  }
  d= (int*)malloc(sizeof(int)*cnt);
  for(int i=0; i<cnt; i++){
    d[i]=(N%Pow(10,i+1))/Pow(10,i);
  }
  for(int j=0; j<cnt; j++){
    for(int k=0; k<cnt-1; k++){
      if(d[k]>d[k+1]){
        int temp = d[k];
        d[k] = d[k+1];
        d[k+1] = temp;
      }
    }
  }
  for(int q=cnt-1; q>-1; q--){
    printf("%d",d[q]);
  }
}
