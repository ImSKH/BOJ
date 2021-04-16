#include <stdio.h>
#include <stdlib.h>
int Pow(int x, int y){
  if(y==0) return 1;
  return x*Pow(x,y-1);
}
int *D(int Ar[], int d, int N){
  for(int i=0; i<d; i++){
    Ar[i] = (N%Pow(10,i+1))/Pow(10,i);
  }
  return Ar;
}
void sort(int Ar[],int n){
  int temp;
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      if(Ar[j]>Ar[j+1]){
        temp = Ar[j];
        Ar[j] = Ar[j+1];
        Ar[j+1] = temp;
      }
    }
  }
}
int main(){
  int N=0,d=0;
  int N0, cnt[10]={0,};
  int *digit;
  int temp;
  scanf("%d",&N);
  if(N==0){
    printf("1");
    return 0;
  }
  N0=N;
  while(N0>0){
    N0 = N0/10;
    d++;
  }

  digit = (int *)malloc(sizeof(int)*d);

  int *Dg = D(digit,d,N);

  //for(int i=0; i<d; i++){
    //printf("%d\n",Dg[i]);}
  for(int i=0; i<10; i++){
    for(int j=0; j<d; j++){
      if(Dg[j]==i) cnt[i]++;
    }
  }

  if((cnt[6]+cnt[9])%2==0) {
    cnt[6] = (cnt[6]+cnt[9])/2;
    cnt[9] = 0;}
  else{
    cnt[6] = (cnt[6]+cnt[9]+1)/2;
    cnt[9] = 0;}

  sort(cnt,10);

  printf("%d",cnt[9]);
  
 
  free(digit);
}
