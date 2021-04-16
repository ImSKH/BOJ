#include <stdio.h>

int power(int x,int y){
  if(y==0) return 1;
  return x*power(x,y-1);
}

int *pal(int n){
  static int digit[5];
  for(int i =0; i<5; i++){
    digit[i]=(n%power(10,i+1)/power(10,i));
  }
  return digit;
}


int main(void) {
  int N=1;
  while(N>0){
    scanf("%d",&N);
    if(N!=0){
      int *num = pal(N);
      int MSB=0;
      int j =5;
      while(MSB==0){
        MSB = num[j];
        j -=1;
      }
      if(N<10) printf("yes\n");
      else{ 
        if(num[0]!=MSB) printf("no\n");
        else if(num[1]!=num[j]) printf("no\n");
        else printf("yes\n");
      }
    }
  }
}
