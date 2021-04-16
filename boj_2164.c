#include <stdio.h>
#include <stdlib.h>

int que[1000000];
int f=0;
int r=-1;

int size(){
  if(f>r) return 0;
  return r-f+1;
}

void Pop(){
  ++f;
}
void Push(int x){
  que[++r] = x;
}
void PopPush(){
  int temp = que[f];
  Pop();
  que[++r] = temp;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    Push(i+1);
  }
  while(size()!=1){
    Pop();
    PopPush();
  }
  printf("%d\n",que[f]);
}
