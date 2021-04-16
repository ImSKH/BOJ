#include <stdio.h>

int que[10000000];
int f=0;
int r=-1;

int empty(){
  if(f>=r) return 1;
  return 0;
}

int full(int N){
  if((r-f)==(N-1)) return 1;
  return 0;
}

void Pop(){
  ++f;
}

void Push(int x){
  que[++r]=x;
}

int main(){
  int N, Inp=0;
  scanf("%d",&N);

  while(1){
    scanf("%d",&Inp);
    //printf("%d",Inp);
    if(Inp==0) Pop();
    else if(full(N)==0) Push(Inp);
    if(Inp==-1) break;  
  }

  if(empty()==1) printf("empty");

  for(int i=f; i<r+1; i++){
    if(que[i]!=-1) printf("%d ",que[i]);
  }
}
