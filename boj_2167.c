#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,M;
  scanf("%d %d",&N,&M);

  int Ar[N][M];
  
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d",&Ar[i][j]);
    }
  }
  int K;
  scanf("%d", &K);

  int ijxy[K][4];
  for(int p=0; p<K; p++){
    for(int q=0; q<4; q++){
      scanf("%d",&ijxy[p][q]);
    }
  }

  int sum[10000]={0,};
  for(int s=0; s<K; s++){
    for(int n=ijxy[s][0]-1; n<ijxy[s][2];n++){
      for(int m=ijxy[s][1]-1; m<ijxy[s][3];m++){
        sum[s]=sum[s]+Ar[n][m];
      }
    }
  }
  for(int s=0; s<K; s++){
    printf("%d\n",sum[s]);
  }

}
