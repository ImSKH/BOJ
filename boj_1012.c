#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 53
int map[MAX][MAX]={0,};
int gr[MAX*MAX]={-1,};
int X,Y;
int dfs(int y,int x){
  if(y<0||x<0||x>=X||y>=Y||map[y][x]==0) return 0;
  map[y][x]=0;
  return 1+dfs(y-1,x)+dfs(y+1,x)+dfs(y,x-1)+dfs(y,x+1);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    memset(map,0,MAX*MAX);
    memset(gr,-1,MAX*MAX);
    int k;
    scanf("%d %d %d",&X,&Y,&k);
    for(int i=0; i<k; i++){
      int a,b;
      scanf("%d %d",&a,&b);
      map[b][a]=1;
    }
    int cnt=0;
    for(int i=0; i<Y; i++){
      for(int j=0; j<X; j++){
        if(map[i][j]==1){
          gr[cnt]=dfs(i,j);
          cnt++;
        }
      }
    }
    printf("%d\n",cnt);
  }
  
}
