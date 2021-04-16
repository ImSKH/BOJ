#include <stdio.h>
#include <stdlib.h>

int stack[100000];
int r=0;

void push(int x){
  stack[++r] = x;
}

void pop(){
    --r; 
}

int main(){
  int N,S,k=1;
  int *Seq;
  char oper[100001];
  int index=0;
  scanf("%d",&N);
  Seq = (int*)malloc(sizeof(int)*N);
  for(int i=0; i<N; i++){
    scanf("%d",&S);
    Seq[i]=S;
  }
  Seq[N]=0;
  for(int i=0; i<N; i++){
    while(Seq[i]!=stack[r]){
      push(k);
      ++k;
      oper[++index]='+';
    }
    pop();
    oper[++index]='-';
    if(Seq[i]>Seq[i+1]){
      if(stack[r]!=Seq[i+1]){
        printf("NO\n");
        return 0;
        }
    }
  }
  for(int i=1; i<index+1; i++){
    printf("%c\n",oper[i]);
  }

  free(Seq);
}
