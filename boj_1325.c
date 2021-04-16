#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10003

typedef struct _node{
  int data;
  struct _node *next;
}node;

node *list[max];
int visit[max];

int big(int a,int b){
  return ((a>b)? a:b);
}

void push(int a, int b){
  node *tmp = (node *)malloc(sizeof(node));
  tmp->next=NULL;
  tmp->data=b;
  if(list[a]==NULL) list[a]=tmp;
  else{
    tmp->next=list[a];
    list[a]=tmp;
  }
}

int dfs(int v){
  int cnt=0;
  visit[v]=1;
  node *tmp=(node *)malloc(sizeof(node));
  for(tmp=list[v];tmp;tmp=tmp->next){
    if(visit[tmp->data]==0)
      cnt+=dfs(tmp->data)+1;
  }
  return cnt;
}

int main(){
  int num[max];
  int n,m,ans=0;
  scanf("%d %d",&n,&m);
  for(int i=0; i<m; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    push(b,a);
  }
  for(int i=1; i<=n; i++){
    num[i] =dfs(i);
    ans=big(ans,num[i]);
    memset(visit,0,sizeof(visit));
  }
  for(int i=1; i<=n; i++){
    if(ans==num[i]) printf("%d ",i);
  }
}
