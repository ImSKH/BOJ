#include <stdio.h>
#include <stdlib.h>

//최단거리 구하기 문제의 경우
//dfs로 풀 때 경로가 아주 많은 경우 시간초과
//bfs는 최단 거리를 보장함.

int maze[103][103]={0,};
int visit[103]={-1,};

typedef struct _node{
  int x;
  int y;
  struct _node *next;
}Queue;

Queue *front=NULL;
Queue *back=NULL;

void push(int y,int x){
  Queue *tmp=(Queue *)malloc(sizeof(Queue));
  tmp->y=y;
  tmp->x=x;
  tmp->next=NULL;
  if(front==NULL&&back==NULL){
    front=tmp;
    back=tmp;
    return;
  }
  tmp->next=back;
  back=tmp;
}

void pop(){
  Queue *tmp=(Queue*)malloc(sizeof(Queue));
  tmp=back;
  while(tmp->next!=front){
    tmp=tmp->next;
  }
  
}
int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%1d",&maze[i][j]);
    }
  }
}
