#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

typedef struct Stack{
  Node *top;
} Stack;

void InitStack(Stack *stack){
  stack->top=NULL;
}

void Push(Stack *stack, int data){
  Node *newN=(Node *)malloc(sizeof(Node));
  newN->data = data;
  newN->next = stack->top;
  stack->top = newN;
}

int Pop(Stack *stack){
  int re;
  Node *newN=(Node *)malloc(sizeof(Node));
  newN = stack->top;
  re = newN->data;
  stack->top=newN->next;
  free(newN);
  return re;
}

int main(){
  int N,X,tmp=0;
  scanf("%d",&N);
  Stack *st = (Stack *)malloc(sizeof(Stack));
  InitStack(st);
  for(int i=0; i<N; i++){
    scanf("%d",&X);
    if(X!=0) Push(st,X); 
    else Pop(st);
  }
  
  if(st->top==NULL){
    printf("0\n");
    return 0;
  }
  Node *curr =st->top;
  while(curr!=NULL){
    tmp+=curr->data;
    curr=curr->next;
  }
  printf("%d\n",tmp);
}
