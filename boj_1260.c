#include <stdio.h>

int visit_dfs[1001];
int visit_bfs[1001];
int queue[1001];
int front=0, rear=0;
int con_Ar[1001][1001];
int n;

void dfs(int v){
  visit_dfs[v]=1;
  for(int i=1; i<=n; i++){
    if(con_Ar[v][i]==1&&visit_dfs[i]==0){
        printf("%d ",i);
        dfs(i);
    }
  }
}

void bfs(int v){
  visit_bfs[v]=1;
  queue[rear++]=v;
  while(front<rear){
    v=queue[front++];
    for(int i=1; i<=n; i++){
      if(con_Ar[v][i]==1&&visit_bfs[i]==0){
          visit_bfs[i]=1;
          printf("%d ",i);
          queue[rear++]=i;
      }
    }
  }
}

int main(){
  int e,s;
  int a,b;
  scanf("%d %d %d",&n,&e,&s);
  for(int i=0; i<e; i++){
    scanf("%d %d",&a,&b);
    con_Ar[a][b]=1;
    con_Ar[b][a]=1;
  }
  printf("%d ",s);
  dfs(s);
  printf("\n");
  printf("%d ",s);
  bfs(s);
  printf("\n");
}
