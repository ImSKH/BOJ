#include <stdio.h>
#include <stdlib.h>

void sort(int *Ar,int N){
  for(int i=0; i<N; i++){
    for(int j=N-2;j>-1;j--){
      if(Ar[j]<Ar[j+1]){
        int temp = Ar[j];
        Ar[j]=Ar[j+1];
        Ar[j+1]=temp;
      }
    }
  }
}

int main(void) {
  int T,N,M;
  int temp,loop=0;
  int *Que;
  scanf("%d",&T);
  for(int i=0; i<T; i++){
    scanf("%d %d",&N,&M);
    Que = malloc(sizeof(int)*N);
    for(int j=0; j<N; j++){
      scanf("%d",&Que[j]);
    }
    temp = Que[M];
    sort(Que,N);

    while(temp!=Que[loop]){
      loop++;
    }
    loop+=1;
    printf("%d\n",loop);
    free(Que);
  }
  
}
