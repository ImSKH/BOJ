#include <stdio.h>
#include <stdlib.h>
#define MAX 26
int n;
int map[MAX][MAX];
int gr[MAX*MAX];

void bsort(int ar[],int size){
  for(int i=0; i<size;i++){
    for(int j=0; j<size-1; j++){
      if(ar[j]>ar[j+1]){
        int tmp=ar[j];
        ar[j]=ar[j+1];
        ar[j+1]=tmp;
      }
    }
  }
}

int dfs(int y,int x){
  if(y<0||x<0||y>=n||x>=n||map[y][x]==0) return 0;
  map[y][x]=0;
  return 1+dfs(y+1,x)+dfs(y-1,x)+dfs(y,x+1)+dfs(y,x-1);
}

int main(){
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%1d",&map[i][j]);
    }
  }
  int cnt=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(map[i][j]==1){
        gr[cnt]=dfs(i,j);
        cnt++;
      }
    }
  }
  bsort(gr,cnt);
  printf("%d\n",cnt);
  for(int i=0; i<cnt; i++){
    printf("%d\n",gr[i]);
  }
}
