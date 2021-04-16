#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node *next;
}node;

node *list[100001];
int visit[100001];
int parent[100001];

void push(int a, int b){
  node *tmp=(node *)malloc(sizeof(node));
  tmp->next=NULL;
  tmp->data=b;
  if(list[a]==NULL) list[a]=tmp;
  else{
    tmp->next=list[a];
    list[a]=tmp;
  }
}

void dfs(int num){
  visit[num]=1;
  node *tmp=(node*)malloc(sizeof(node));
  for(tmp=list[num];tmp!=NULL;tmp=tmp->next){
    if(visit[tmp->data]==0){
      parent[tmp->data]=num;
      dfs(tmp->data);
    }
  }
  return;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    push(a,b);
    push(b,a);
  }
  parent[1]=0;
  for(int i=1; i<=N; i++){
    if(visit[i]==0) dfs(i);
  }
  for(int i=2; i<=N; i++){
    printf("%d\n",parent[i]);
  }
  return 0;
}
