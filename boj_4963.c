#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAP 53

int map[MAP][MAP];
int X=1,Y=1;

int dfs(int y,int x){
  if(y<0||x<0||y>=Y||x>=X||map[y][x]==0) return 0;
  map[y][x]=0;
  return 1+dfs(y-1,x)+dfs(y+1,x)+dfs(y,x-1)+dfs(y,x+1)+dfs(y-1,x-1)+dfs(y-1,x+1)+dfs(y+1,x-1)+dfs(y+1,x+1);
}

int main(){
  while(X!=0||Y!=0){
    int cnt=0,tmp=0;
    memset(map,-1,MAP*MAP);
    scanf("%d %d",&X,&Y);
    for(int i=0; i<Y; i++){
      for(int j=0; j<X; j++){
        scanf("%d",&map[i][j]);
      }
    }
    for(int i=0; i<Y; i++){
      for(int j=0; j<X; j++){
        if(map[i][j]==1){
          tmp=dfs(i,j);
          cnt++;
        }
      }
    }
    if(X==0&&Y==0) continue;
    printf("%d\n",cnt);
  }
}
