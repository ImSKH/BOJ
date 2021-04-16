#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 103

int map[MAX/*y*/][MAX/*x*/]={0,};
int tmpmap[MAX][MAX]={1,};
int N,safe,tmp;
int cnt[MAX]={-1,};

int dfs(int y, int x){
  if(y<0||x<0||y>=N||x>=N||tmpmap[y][x]==0) return 0;
  tmpmap[y][x]=0;
  return 1+dfs(y-1,x)+dfs(y+1,x)+dfs(y,x-1)+dfs(y,x+1);
}

int main(){
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%d",&map[i][j]);
    }
  }
  for(int wt=0; wt<101; wt++){
    memset(tmpmap,0,MAX*MAX);
    safe=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(map[i][j]>wt) tmpmap[i][j]=1;
      }
    }
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(tmpmap[i][j]==1){
          tmp=dfs(i,j);
          safe++;
        }
      }
    }
    cnt[wt]=safe;
  }
  int maxcnt=0;
  for(int i=0; i<101; i++){
    if(maxcnt<cnt[i]){
      maxcnt=cnt[i];
    }
  }
  printf("%d\n",maxcnt);
}
