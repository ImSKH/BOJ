#include <stdio.h>
#include <stdlib.h>
#define MAX 1005

int conAr[MAX][MAX]={0,};
int visit[MAX]={0,};
int N,M;
int cnt=0;

void dfs(int v){
  visit[v]=1;
  for(int i=1; i<=N; i++){
    if(conAr[v][i]==1&&visit[i]==0){
      dfs(i);
    }
  }
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0; i<M; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    conAr[a][b]=conAr[b][a]=1;
  }
  for(int i=1; i<=N; i++){
      if(visit[i]==0){
        dfs(i);
        cnt++;
    }
  }
  printf("%d\n",cnt);
}
