#include <stdio.h>
#include <stdlib.h>
int power(int x, int y){
  if(y==0) return 1;
  return x*power(x,y-1);
}

int main(){
  int k,N;
  int *node;
  scanf("%d",&k);
  N=power(2,k)-1;
  node=malloc(sizeof(int)*N);
  for(int i=0; i<N; i++) scanf("%d",&node[i]);
  for(int i=0; i<k;i++){
    for(int j=0; j<power(2,i); j++) printf("%d ",node[(2*j+1)*N/power(2,i+1)]);
    printf("\n");
  }
