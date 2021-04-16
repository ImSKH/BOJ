#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node *prev;
  struct _node *next;
}Node;

typedef struct _deque{
  Node *front;
  Node *rear;
  int size;
} Deque;

void MakeDeque(Deque *deque){
  deque->front=deque->rear=NULL;
  deque->size=0;
}

int IsEmpty(Deque *deque){
  if(deque->size==0) return 1;
  return 0;
}

void Push_front(Deque *deque, int data){
  Node *newN=(Node *)malloc(sizeof(Node));
  newN->data = data;
  if(IsEmpty(deque)){
    deque->front = deque -> rear = newN;
    deque->front->prev = NULL;
    deque->rear->next = NULL;
    deque->size++;
    return;
  }
  newN->next=deque->front;
  deque->front->prev=newN;newN->prev=NULL;
  deque->front=newN;
  deque->size++;
}

void Push_rear(Deque *deque, int data){
  Node *newN=(Node *)malloc(sizeof(Node));
  newN->data = data;
  if(IsEmpty(deque)){
    deque->front=deque->rear=newN;
    deque->front->prev=NULL;
    deque->rear->next=NULL;
    deque->size++;
    return;
  }
  newN->prev=deque->rear;
  deque->rear->next=newN;
  newN->next=NULL;
  deque->rear=newN;
  deque->size++;
}

int Pop_front(Deque *deque){
  if(IsEmpty(deque)) return -1;
  Node *curr = deque->front;
  int re=0;
  re = curr->data;
  if(deque->size==1){
    MakeDeque(deque);
    return re;
  }
  curr->prev = NULL;
  curr->next = deque->front->next;
  deque->front = curr->next;
  deque->size--;
  return re;
}

int Pop_rear(Deque *deque){
  if(IsEmpty(deque)) return -1;
  Node *curr = deque->rear;
  int re=0;
  re = curr->data;
  if(deque->size==1){
    MakeDeque(deque);
    return re;
  }
  curr->next = NULL;
  curr->prev = deque->rear->prev;
  deque->rear = curr->prev;
  deque->size--;
  return re;
}

int front(Deque *deque){
  if(IsEmpty(deque)) return -1;
  return deque->front->data;
}

int back(Deque *deque){
  if(IsEmpty(deque)) return -1;
  return deque->rear->data;
}

int main(){
  int N,X;
  char O[12];
  Deque *deque=(Deque *)malloc(sizeof(Deque));
  MakeDeque(deque);
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%s",O);
    if(O[0]=='s') printf("%d\n",deque->size);
    else if(O[0]=='e') printf("%d\n",IsEmpty(deque));
    else if(O[0]=='f') printf("%d\n",front(deque));
    else if(O[0]=='b') printf("%d\n",back(deque));
    else if(O[1]=='u'){
      scanf("%d",&X);
      if(O[5]=='f') Push_front(deque,X);
      else Push_rear(deque, X);
    }
    else if(O[1]=='o'){
      if(O[4]=='f') printf("%d\n",Pop_front(deque));
      else printf("%d\n",Pop_rear(deque));
    }
  }
}
