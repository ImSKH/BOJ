#include <stdio.h>
#include <stdlib.h>
#define max 103
int adj[max][max]={0,};

int main(){
  int N,M;
  int x,y;
  scanf("%d",&N);
  scanf("%d %d",&x,&y);
  scanf("%d",&M);

  for(int i=0; i<M; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    adj[a][b]=adj[b][a]=1;
  }
  

}
