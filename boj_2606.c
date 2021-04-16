#include <stdio.h>

int connectAr[103][103]={0,};
int visit[103]={0,};
int n;
int cnt=0;
int dfs(int v){
  cnt++;
  visit[v]=1;
  for(int i=1; i<=n; i++){
    if(connectAr[v][i]==1&&visit[i]==0) {
      dfs(i);
    }
  }
  return cnt;
}

int main(){
  int com,con;
  scanf("%d",&n);
  scanf("%d",&con);
  for(int i=0; i<con; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    connectAr[a][b]=connectAr[b][a]=1;
  }
  int cnt = dfs(1);
  printf("%d",cnt-1);
}
