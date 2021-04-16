#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define que_size 10000

int queue[que_size];
int front = 0;
int rear = -1;

int Empty(){
  if(front>rear) {
    return true;
  }
  else{
    return false;
  } 
}

int Size(){
  if(Empty()) return 0;
  else return  rear-front+1;
}

void Pop(){
  if(Empty()) printf("-1\n");
  else{
    printf("%d\n",queue[front]);
    front = front+1;
  }
}

void Push(int X){
  rear = rear+1;
  queue[rear]=X;
  }

void Front(){
  if(Empty()) printf("-1\n");
  else printf("%d\n",queue[front]);
}

void Back(){
  if(Empty()) printf("-1\n");
  else printf("%d\n",queue[rear]);
}

int main(){
  int N,K;
  char Od[30];
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%s",Od);
    if(strcmp(Od,"push")==0) scanf("%d",&K);
    if(strcmp(Od,"push")==0) Push(K);
    else if(strcmp(Od,"front")==0) Front();
    else if(strcmp(Od,"back")==0) Back();
    else if(strcmp(Od,"pop")==0) Pop();
    else if(strcmp(Od,"size")==0) printf("%d\n",Size());
    else if(strcmp(Od,"empty")==0) printf("%d\n",Empty());
  }
}
