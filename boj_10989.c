#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  int num;
  int cnt[10001]={0,};
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%d",&num);
    cnt[num]++;
  }
  for(int i=0; i<=10000; i++){
    for(int j=0; j<cnt[i]; j++){
      printf("%d\n",i);
    }
  }
}
