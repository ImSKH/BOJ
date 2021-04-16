#include <stdio.h>

int stack[10000];
int r=-1;

int empty(){
  if(r==-1) return 1;
  return 0;
}

int size(){
  if(empty()) return 0;
  return (r+1);
}

void top(){
  if(empty()) printf("-1\n");
  else printf("%d\n",stack[r]);
}

void pop(){
  if(empty()) printf("-1\n");
  else{
    printf("%d\n",stack[r]);
    --r;
  }
}

void push(int x){
  stack[++r] = x;
}

int main(){
  int N,X;
  char Or[6];
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%s",Or);
    if(Or[1]=='u'){
     scanf("%d",&X);
     push(X);
    }
    else if(Or[0]=='p'&&Or[1]=='o'){
     pop();
    }
    else if(Or[0]=='s'){
      printf("%d\n",size());
    }
   else if(Or[0]=='e'){
     printf("%d\n",empty());
    }
    else if(Or[0]=='t'){
      top();
    }
  }

}
