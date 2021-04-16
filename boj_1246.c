#include <stdio.h>
void sort(int Arr[], int N){
  int temp;
  for(int i=0; i<N; i++){
    for(int j=0; j<N-1; j++){
      if(Arr[j]>Arr[j+1]){
        temp = Arr[j];
        Arr[j] = Arr[j+1];
        Arr[j+1] = temp;
      }
    }
  }
}

int main(void) {
  int N,M;
  scanf("%d %d",&N,&M);
  int cus_P[M];
  for(int i=0; i<M; i++){
    scanf("%d",&cus_P[i]);
  }
  sort(cus_P,M);
  printf("%d\n",cus_P[M-1]);
  int cnt[M];
  int choice_P, total[M];
  for(choice_P=0; choice_P<cus_P[M-1]+1;choice_P++){
    for(int i=0; i<M; i++){
      if(choice_P<cus_P[i]) cnt[i]++;
    }
  }
  for(int i=0; i<M; i++){
    printf("%d ",cnt[i]);
  }
  printf("\n");
  for(int k=0; k<M; k++){
    if(cnt[k]>N) cnt[k]=N;
  }
  for(int i=0; i<M; i++){
    printf("%d ",cnt[i]);
  }
  for(int p=0; p<M; p++) total[p]=(p+1)*cnt[p];

  sort(total,M);
  int Pri;
  for(int q=0; q<M; q++){
    if((q+1)*cnt[q]==total[M-1]) Pri=q;
  }
  printf("%d %d",Pri,total[M-1]);
}
