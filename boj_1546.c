#include <stdio.h>
#include <stdlib.h>

void sort(double score[], int N){
  int temp=0;
  for(int i=0 ; i<N; i++){
    for(int j=0; j<N-1; j++){
      if(score[j]>score[j+1]){
        temp = score[j];
        score[j]=score[j+1];
        score[j+1]=temp;
      }
    }
  }
}

int main(){
  double *SC;
  int N,M;
  double avr=0;
  scanf("%d",&N);
  SC = (double *)malloc(sizeof(double) * N);
  for(int i =0; i<N; i++) scanf("%lf", 
  &SC[i]);
  //for(int i =0; i<N; i++) printf("%d ", SC[i]);
  sort(SC,N);
  printf("\n");
  //입력 받은 배열을 sort 완료
  //for(int i =0; i<N; i++) printf("%d ", SC[i]);
  //%g 출력시 소수점 뒤 0제거

  M = SC[N-1];
  //printf("%d",M);
  for(int j=0; j<N; j++){
    SC[j] = (SC[j]/M)*100;
  }
  //for(int i =0; i<N; i++) printf("%d ", SC[i]);

  for(int k = 0; k<N ;k++){
    avr = avr + SC[k];
    }
  avr = avr/N;

  printf("%g",avr);
}
